#include "Serializer.hpp"
#include "BmpFileFormat.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <termios.h>
#include <unistd.h>

const uint8_t Serializer::palette[][3] =
{
	// GRAY
	{
		245,
		235,
		225
	},
	// RGB
	{
		180,
		18,
		5
	},
	// PURPLE
	{
		82,
		81,
		80
	}
};


// OCCF
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer&)
{
}

void	Serializer::operator=(const Serializer&)
{
}

Serializer::~Serializer()
{
}

void	Serializer::setRawMode(const bool enable)
{
	static struct termios oldt;
	static struct termios newt;

	if (enable == true)
	{
	    // 터미널을 raw 모드로 설정
	    tcgetattr(0, &oldt);
	    newt = oldt;
	    newt.c_lflag &= ~(ICANON | ECHO);
	    tcsetattr(0, TCSANOW, &newt);
	}
	else
	{
	    // 원래 터미널 설정 복원
	    tcsetattr(0, TCSANOW, &oldt);
	}
}

void	Serializer::clearPixel(Data& data)
{
	for (uint32_t j = 0; j < data.terminal_height; j++)
	{
		std::memset(data.terminal_pixel_data[j], 0, data.terminal_width);
	}

	initScreen(data);
}

uint8_t	Serializer::checkEscape(char* cptr)
{
	for (uint8_t i = 0; i < 2; i++)
	{
		std::cin.read(cptr, 1);
		if (*cptr != "\033["[i])
		{
			return 0;
		}
	}
	return 1;
}

// 유저가 픽셀을 입력하는 즉시 배열에 저장하고 화면에 띄운다.
uint32_t	Serializer::getPixel(Data& data)
{
	char		c;
	uint32_t	ret = 0;
	if (checkEscape(&c) == 1) // move cursor if escape
	{
		std::cin.read(&c, 1);
		if (c == 'A' && data.tj > 0)
		{
			std::cout << CURSOR_UP;
			--(data.tj);
		}
		else if (c == 'B' && data.tj < data.terminal_height - 1)
		{
			std::cout << CURSOR_DOWN;
			++(data.tj);
		}
		else if (c == 'C' && data.ti < data.terminal_width)
		{
			std::cout << CURSOR_RIGHT;
			++(data.ti);
		}
		else if (c == 'D' && data.ti > 0)
		{
			std::cout << CURSOR_LEFT;
			--(data.ti);
		}
	}
	else // draw pixel or others
	{
		if (c == 'L')
		{
			clearPixel(data);
		}
		else if (c == '\n') // 입력 끝?
		{
			ret = chooseOption(data, FINISH_DRAWING, 3);
		}
		else if ((c == '1' || c == '2' || c == '3' || c == '4') && data.ti < data.terminal_width)
		{
			data.terminal_pixel_data[data.tj][data.ti] = c - '0';
			++(data.ti);
			std::cout << c;
		}
		else if (c == 127 && (data.ti > 0 && data.ti <= data.terminal_width))
		{
			--(data.ti);
			data.terminal_pixel_data[data.tj][data.ti] = 0;
			std::cout << "\033[D" << c << "\033[D";
		}
	}
	return ret;
}

void	Serializer::displayOption(Data& data, enum optionDisplayMode mode, int8_t option)
{
	static const char*	option_box[][5] =
	{
		{
			"┌───────────────────────────┐",
			"│      Select  bgcolor      │",
			"│                           │",
			"│     [black]   [white]     │",
			"└───────────────────────────┘"
		},
		{
			"┌───────────────────────────┐",
			"│      Select  palette      │",
			"│                           │",
			"│   [GRAY] [RGB] [PURPLE]   │",
			"└───────────────────────────┘"
		},
		{
			"┌───────────────────────────┐",
			"│      Finish  drawing      │",
			"│                           │",
			"│ [Continue] [Save] [Draft] │",
			"└───────────────────────────┘"
		},
		{
			"┌───────────────────────────┐",
			"│      Select   action      │",
			"│                           │",
			"│     [New]   [Drafted]     │",
			"└───────────────────────────┘"
		},
		{
			"                             ",
			"                             ",
			"                             ",
			"                             ",
			"                             "
		}
	};
	static const char*	option_highlight[][3] =
	{
		{
			"│     \033[44m[black]\033[0m   [white]     │",
			"│     [black]   \033[44m[white]\033[0m     │",
			""
		},
		{
			"│   \033[44m[GRAY]\033[0m [RGB] [PURPLE]   │",
			"│   [GRAY] \033[44m[RGB]\033[0m [PURPLE]   │",
			"│   [GRAY] [RGB] \033[44m[PURPLE]\033[0m   │",
		},
		{
			"│ \033[44m[Continue]\033[0m [Save] [Draft] │",
			"│ [Continue] \033[44m[Save]\033[0m [Draft] │",
			"│ [Continue] [Save] \033[44m[Draft]\033[0m │"
		},
		{
			"│     \033[44m[New]\033[0m   [Drafted]     │",
			"│     [New]   \033[44m[Drafted]\033[0m     │",
			""
		}
	};

	uint32_t	tab_vert = 10;
	uint32_t	tab_horiz = 0;
	if (mode == PALETTE_TYPE)
	{
		tab_vert += 5;
	}
	else if (mode == FINISH_DRAWING || mode == CLEAR)
	{
		tab_vert = 14;
		tab_horiz = data.terminal_width + 6;
	}
	else if (mode == CHOOSE_SD)
	{
		tab_vert = 1;
	}

	for (uint8_t i = 0; i < 5; i++)
	{
		std::cout << "\033[" << tab_vert++ << ";" << tab_horiz << "H";
		std::cout << option_box[mode][i] << "\n";
	}

	if (mode != CLEAR)
	{
		std::cout << "\033[" << tab_vert - 2 << ";" << tab_horiz << "H";
		std::cout << option_highlight[mode][option];
	}
}

uint8_t	Serializer::chooseOption(Data& data, enum optionDisplayMode mode, uint8_t button_number)
{
	// 커서 숨기기
	std::cout << "\033[?25l";

	displayOption(data, mode, FIRST);
	int8_t	option = FIRST;

	char	c;
	for (;;)
	{
		if (checkEscape(&c) == 1)
		{
			std::cin.read(&c, 1);
			if (c == 'C')
			{
				option = (option + 1) % button_number;
			}
			else if (c == 'D')
			{
				option = (option - 1 + button_number) % button_number;
			}
			displayOption(data, mode, option);
		}
		else if (c == '\n')
		{
			if (mode == FINISH_DRAWING)
			{
				displayOption(data, CLEAR, FIRST);
				if (option == FIRST)
				{
					// 커서 위치 복원
					std::cout << "\033[" << data.tj + 2 << ";" << data.ti + 2 << "H";
				}
				else if (option == THIRD)
				{
					data.magic_number = 0x4A53;
					data.filename += "_draft";
					option = 1;
				}
			}
			break;
		}
	}


	// 커서 보이기
	std::cout << "\033[?25h";

	return option;
}

void	Serializer::setColorIndex(Data& data)
{
	data.color_index[0] = data.bgcolor;
	data.color_index[1] = palette[data.palette_type][0];
	data.color_index[2] = palette[data.palette_type][1];
	data.color_index[3] = palette[data.palette_type][2];
	data.color_index[4] = ~(data.bgcolor);
}

uint32_t	Serializer::setConfig(Data& data)
{
	std::cout << "\033[6;0H";

	data.magic_number = 0x4D42;

	std::string	user_input;
	// get user input width
	std::cout << "[Enter image width]: ";
	getline(std::cin, user_input);
	std::istringstream(user_input) >> data.image_width;
	// get user input height
	std::cout << "[Enter image height]: ";
	getline(std::cin, user_input);
	std::istringstream(user_input) >> data.image_height;

	// 10의 자리로 반올림하고 10으로 나눈다.
	data.terminal_width = (data.image_width % 10) >= 5 ? (data.image_width + 10) / 10 : data.image_width / 10;
	data.terminal_height = (data.image_height % 10) >= 5 ? (data.image_height + 10) / 10 : data.image_height / 10;

	data.image_width = data.terminal_width * 10;
	data.image_height = data.terminal_height * 10;

	if (data.terminal_width == 0 || data.terminal_height == 0)
	{
		std::cerr << "Width and height of the image must be at least 10." << std::endl;
		return 0;
	}

	std::cout << "[Enter filename]: ";
	std::cout << "\n(output: <filename>.bmp)\033[A\033[6D";
	getline(std::cin, data.filename);

	setRawMode(true);

	data.bgcolor = chooseOption(data, BGCOLOR, 2) * 0xFF;
	data.palette_type = chooseOption(data, PALETTE_TYPE, 3);

	setColorIndex(data);

	return 1;
}

void	Serializer::initScreen(Data& data)
{
	const char*	palette_name[3] = { "GRAY", "RGB", "PURPLE" };
	const char*	background_name[2] = { "BLACK", "WHITE" };

	data.ti = 0;
	data.tj = 0;

	std::cout << CLEAR_SCREEN;

	std::ostringstream	oss;
	for (uint32_t i = 0; i < data.terminal_width; i++)
	{
		oss << "═";
	}
	std::cout << "╔" << oss.str() << "╗\n";

	for (uint32_t i = 0; i < data.terminal_height; i++)
	{
		std::cout << "║\033[" << data.terminal_width << "C║\n";
	}
	std::cout << "╚" << oss.str() << "╝";

	// 현재 세팅
	std::cout << LEFT_TOP << "\033[" << data.terminal_width + 5 << "C" \
		<< "[ PROPERTIES ]\n\033["<< data.terminal_width + 6 << "C" \
		<< "Palette: " << palette_name[data.palette_type] << "\n\033[" << data.terminal_width + 6 << "C" \
		<< "Bgcolor: " << background_name[data.bgcolor / 0xFF] << "\n\n";

	// 안내사항
	std::cout << "\033[" << data.terminal_width + 6 << "C" \
		<< "[ USAGE ]\n" << "\033[" << data.terminal_width + 6 << "C" \
		<< "1. Move the cursor by the arrow keys.\n" << "\033[" << data.terminal_width + 6 << "C" \
		<< "2. Enter the color by { 1, 2, 3, 4 }.\n" << "\033[" << data.terminal_width + 6 << "C" \
		<< "  - { 1, 2, 3 } are the three palette colors and 4 is the color opposite to the background color.\n"  << "\033[" << data.terminal_width + 6 << "C" \
		<< "3. Enter <backspace> to erase the pixel.\n" << "\033[" << data.terminal_width + 6 << "C" \
		<< "4. Enter 'L' to clear the screen.\n" << "\033[" << data.terminal_width + 6 << "C" \
		<< "5. Enter <Enter> to finish or draft the job.\n";
	std::cout << LEFT_TOP << std::flush;
}

// catch문은 바깥에 있음.
void	Serializer::draw(Data& data)
{
	if (data.terminal_pixel_data == NULL)
	{
		data.terminal_pixel_data = new uint8_t*[data.terminal_height]();

		for (uint32_t i = 0; i < data.terminal_height; i++)
		{
			data.terminal_pixel_data[i] = new uint8_t[data.terminal_width]();
		}
	}
	else
	{
		for (uint32_t j = 0; j < data.terminal_height; j++)
		{
			std::cout << "\033[" << j + 2 << ";2H";
			for (uint32_t i = 0; i < data.terminal_width; i++)
			{
				if (data.terminal_pixel_data[j][i] == 0)
				{
					std::cout << ' ';
				}
				else
				{
					char	c = data.terminal_pixel_data[j][i] + '0';
					std::cout << c;
				}
			}
		}
		std::cout << LEFT_TOP;
	}

	for (;;)
	{
		if (getPixel(data) == 1)
		{
			break;
		}
	}

	std::cout << "\033[" << data.terminal_width + 2 << ";" << 0 << "H" << std::endl;

	setRawMode(false);
}

Data*	Serializer::generateImgData()
{
	Data*	data = NULL;

	try
	{
		data = new Data();

		if (setConfig(*data) == 0)
		{
			throw std::exception();
		}

		initScreen(*data);
		draw(*data);

		data->filename += ".bmp";
	}
	catch (const std::exception& e)
	{
		if (data != NULL)
		{
			freeTerminalData(data);
		}
		delete data;
		data = NULL;
	}

	return data;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
/////INFO//////HEADER///////////////////////////////////
	struct BmpInfoHeader	info_header;

	info_header.size = sizeof(struct BmpInfoHeader);
	info_header.width = ptr->image_width;
	info_header.height = ptr->image_height;
	info_header.color_plane = 1;
	info_header.bits_per_pixel = BITS_DEFAULT;
	// BI_RGB = 0. no compression.
	info_header.compression = 0;
	info_header.image_size = 0;
	// resolution = 미터당 픽셀 밀집도. 기본값 = 0.
	info_header.horizontal_resolution = 0;
	info_header.vertical_resolution = 0;
	// palette를 사용하지 않을 때(bits_per_pixel > 8)는 0.
	info_header.color_number = 1 << info_header.bits_per_pixel;
	info_header.color_number_important = 0;

	// 색상 개수 * 4. 바이트 단위.
	uint32_t	color_table_size = info_header.color_number << 2;

/////FILE//////HEADER///////////////////////////////////
	struct BmpFileHeader	file_header;

	file_header.type = ptr->magic_number;
	// file header size + info header size + palette size + pixel data
	// 각 픽셀 크기는 bits_per_pixel에 따름, 픽셀 개수는 너비와 동, 패딩 사이즈 = (4 - (pixel % 4)) % 4
	// palette 크기는 조건부. 비트 깊이가 8비트 이하일 때만 적용.
	// 사이즈는 모두 바이트 단위.
	// 픽셀 하나에 할당되는 바이트 수. // 8로 올림을 한 뒤 잘랐는데 지금 시점에서는 의미 없어보임.
	uint16_t	pixel_size = (info_header.bits_per_pixel + 7) >> 3;
	// 행 하나에 할당되는 바이트 수.
	uint32_t	row_size_byte = info_header.width * pixel_size;
	// 각 행을 4의 배수로 패딩.
	// 모자란 바이트 수 % 4 (4 - 0 = 4 방지)
	uint32_t	padding = (4 - (row_size_byte % 4)) % 4;
	// 패딩 처리한 행의 바이트 수.
	uint32_t	padded_row_size = row_size_byte + padding;
	// 패딩 처리한 너비 * 높이.
	// 이미지에 삽입할 픽셀 데이터의 최종 크기.
	uint32_t	padded_matrix_size = info_header.height * padded_row_size;
	file_header.size = \
					   sizeof(struct BmpFileHeader) \
					   + sizeof(struct BmpInfoHeader) \
					   + color_table_size \
					   + padded_matrix_size;

	file_header.reserved_1 = 0;
	file_header.reserved_2 = 0;
	file_header.offbits = \
						  sizeof(struct BmpFileHeader) \
						  + sizeof(struct BmpInfoHeader) \
						  + color_table_size;

/////COLOR//////TABLE///////////////////////////////////

	uint8_t*		color_table = NULL;
	uint8_t*		pixel_data = NULL;
	std::ofstream	outfile;
	uintptr_t		ret;

	try
	{
		color_table = new uint8_t[color_table_size];

		for (uint16_t i = 0; i < info_header.color_number; i++)
		{
			uint16_t index = i << 2; // RGBA 인덱스 (i * 4)

			if (i < 216) {
				// 216색 RGB 조합 (6단계씩)
				uint8_t r = (i / 36) % 6;       // R 값 (0~5)
				uint8_t g = (i / 6) % 6;        // G 값 (0~5)
				uint8_t b = i % 6;              // B 값 (0~5)

				color_table[index] = b * 51;        // B 채널
				color_table[index + 1] = g * 51;    // G 채널
				color_table[index + 2] = r * 51;    // R 채널
				color_table[index + 3] = 0;         // Alpha 채널 (0)
			}
			else
			{
				// 39색 회색조 추가
				uint8_t gray = (i - 216) * 6;   // 회색 단계 (0~255)
				color_table[index] = gray;          // R = G = B
				color_table[index + 1] = gray;
				color_table[index + 2] = gray;
				color_table[index + 3] = 0;         // Alpha 채널 (0)
			}
		}

/////PIXEL//////DATA////////////////////////////////////

		pixel_data = new uint8_t[padded_matrix_size];

		for (uint32_t j = 0; j < info_header.height; j++)
		{
			uint32_t	line_gap = j * padded_row_size;
			uint32_t	_j = j / 10;
			uint32_t	i = 0;
			for ( ; i < info_header.width; i++)
			{
				pixel_data[line_gap + i] = ptr->color_index[ptr->terminal_pixel_data[_j][i / 10]];
			}

			for ( ; i < padded_row_size; i++)
			{
				pixel_data[line_gap + i] = 0;
			}
		}

/////GENERATE///////IMAGE///////////////////////////////

		const char*	_filename = ptr->filename.c_str();
		ret = reinterpret_cast<uintptr_t>(_filename);
		outfile.open(_filename, std::ios::binary);
		if (outfile.is_open() == 0)
		{
			std::cerr << "Cannot open file" << std::endl;
			throw std::exception();
		}

		// write file header
		outfile.write(reinterpret_cast<const char*>(&file_header), sizeof(struct BmpFileHeader));

		// write info header
		outfile.write(reinterpret_cast<const char*>(&info_header), sizeof(struct BmpInfoHeader));

		// write color_table if needed
		if (info_header.color_number != 0)
		{
			outfile.write(reinterpret_cast<const char*>(color_table), color_table_size);
		}

		// write pixel data
		for (uint32_t i = padded_matrix_size - padded_row_size; i > 0; i -= padded_row_size)
		{
			outfile.write(reinterpret_cast<const char*>(&pixel_data[i]), padded_row_size);
		}
		outfile.write(reinterpret_cast<const char*>(&pixel_data[0]), padded_row_size);

		if (ptr->magic_number == 0x4A53)
		{
			outfile.write(reinterpret_cast<const char*>(&(ptr->palette_type)), sizeof(uint8_t));
			outfile.write(reinterpret_cast<const char*>(&(ptr->bgcolor)), sizeof(uint8_t));
		}
	}
	catch (const std::exception& e)
	{
		ret = 0;
	}

	delete[] color_table;
	delete[] pixel_data;

	outfile.close();

	return ret;
}

// raw == draft filename
Data*	Serializer::deserialize(uintptr_t raw)
{
	char*	_filename = reinterpret_cast<char*>(raw);
	struct BmpFileHeader	file_header;
	struct BmpInfoHeader	info_header;

	std::ifstream	infile(_filename, std::ios::binary);
	if (infile.is_open() == 0)
	{
		std::cerr << "Cannot open file" << std::endl;
		return NULL;
	}

// CHECK IF IT IS A DRAFT FILE
	infile.read(reinterpret_cast<char*>(&(file_header.type)), 2);
	if (file_header.type != 0x4A53)
	{
		// is not a draft file
		return NULL;
	}

	infile.seekg(16, std::ios::cur);
	infile.read(reinterpret_cast<char*>(&(info_header.width)), 4);
	infile.read(reinterpret_cast<char*>(&(info_header.height)), 4);

	if (info_header.width % 10 != 0 || info_header.height % 10 != 0)
	{
		// is not a draft file
		return NULL;
	}

	infile.seekg(2, std::ios::cur);
	infile.read(reinterpret_cast<char*>(&(info_header.bits_per_pixel)), 2);

	infile.seekg(10, std::ios::beg);
	infile.read(reinterpret_cast<char*>(&(file_header.offbits)), 4);
	infile.seekg(file_header.offbits, std::ios::beg);

// READ PIXEL DATA
	uint16_t	pixel_size = (info_header.bits_per_pixel + 7) >> 3;
	// 행 하나에 할당되는 바이트 수.
	uint32_t	row_size_byte = info_header.width * pixel_size;
	// 각 행을 4의 배수로 패딩.
	uint32_t	padding = (4 - (row_size_byte % 4)) % 4;
	uint32_t	matrix_size = info_header.height * info_header.width;

	uint8_t*	pixel_data = NULL;
	Data*	ptr = NULL;
	try
	{
		pixel_data = new uint8_t[matrix_size];
		// 뒤집어서 저장.
		for (uint32_t j = info_header.height; j > 0; j--)
		{
			uint32_t line_gap = (j - 1) * info_header.width;
			infile.read(reinterpret_cast<char*>(pixel_data + line_gap), info_header.width);
			infile.seekg(padding, std::ios::cur);
		}

		uint8_t	_palette_type = 0;
		infile.read(reinterpret_cast<char*>(&_palette_type), sizeof(uint8_t));

		uint8_t	_bgcolor = 0;
		infile.read(reinterpret_cast<char*>(&_bgcolor), sizeof(uint8_t));
		uint8_t	_rev_bgcolor = ~_bgcolor;

		for (uint32_t i = 0; i < matrix_size; i++)
		{
			uint32_t	k = 0;
			for (; k < 3; k++)
			{
				if (pixel_data[i] == palette[_palette_type][k])
				{
					pixel_data[i] = k + 1;
					break;
				}
			}

			if (k == 3)
			{
				if (pixel_data[i] == _bgcolor)
				{
					pixel_data[i] = 0;
				}
				else if (pixel_data[i] == _rev_bgcolor)
				{
					pixel_data[i] = 4;
				}
				else
				{
					throw std::exception();
				}
			}
		}

// DESERIALIZE
		ptr = new Data();
		ptr->magic_number = 0x4D42;
		ptr->image_width = info_header.width;
		ptr->image_height = info_header.height;
		ptr->terminal_width = info_header.width / 10;
		ptr->terminal_height = info_header.height / 10;
		ptr->filename = _filename;

		size_t	pos = ptr->filename.rfind("_draft.bmp");
		if (pos != std::string::npos)
		{
			ptr->filename.erase(pos);
		}

		ptr->palette_type = _palette_type;
		ptr->bgcolor = _bgcolor;
		setColorIndex(*ptr);

		ptr->terminal_pixel_data = new uint8_t*[ptr->terminal_height]();
		for (uint32_t j = 0; j < ptr->terminal_height; j++)
		{
			ptr->terminal_pixel_data[j] = new uint8_t[ptr->terminal_width];
			uint32_t	line_gap = j * 10 * ptr->image_width;
			for (uint32_t i = 0; i < ptr->terminal_width; i++)
			{
				ptr->terminal_pixel_data[j][i] = pixel_data[line_gap + i * 10];
			}
		}
	}
	catch (const std::exception& e)
	{
		if (ptr != NULL)
		{
			freeTerminalData(ptr);
		}
		delete ptr;
		ptr = NULL;
	}

	delete[] pixel_data;

	infile.close();

	return ptr;
}

uint32_t	Serializer::reloadTerminalData(Data* data)
{
	setRawMode(true);

	try
	{
		initScreen(*data);
		draw(*data);

		data->filename += ".bmp";
	}
	catch (const std::exception& e)
	{
		freeTerminalData(data);
		return 0;
	}

	return 1;
}

uint8_t	Serializer::chooseSD()
{
	setRawMode(true);

	std::cout << CLEAR_SCREEN;

	Data	data;
	data.terminal_width = 0;
	uint8_t	selected_option = chooseOption(data, CHOOSE_SD, 2);

	std::cout << "\033[6;0H";

	setRawMode(false);

	return selected_option;
}

void	freeTerminalData(Data* data)
{
	if (data->terminal_pixel_data != NULL)
	{
		for (uint32_t i = 0; i < data->terminal_height; i++)
		{
			delete data->terminal_pixel_data[i];
		}

		delete[] data->terminal_pixel_data;
		data->terminal_pixel_data = NULL;
	}
}
