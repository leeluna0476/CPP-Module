#include "Serializer.hpp"
#include <iostream>

static void	bootSerialization(Data* data)
{
	char*	generated_file = reinterpret_cast<char*>(Serializer::serialize(data));

	if (generated_file == NULL)
	{
		std::cerr << "Cannot serialize the file." << std::endl;
	}
	else
	{
		std::cout << "[" << data->filename << "]" << std::endl;
	}
}

int	main(void)
{
	// serialize
	Data*	data;
	if (Serializer::chooseSD() == FIRST)
	{
		data = Serializer::generateImgData();

		if (data == NULL)
		{
			std::cerr << "Cannot generate data." << std::endl;
		}
		else
		{
			bootSerialization(data);
			freeTerminalData(data);
			delete data;
		}
	}
	else
	{
		std::string	_filename;
		std::cout << "[Enter filename]: ";
		std::cout << "\n(<filename>.bmp)" << CURSOR_RIGHT << CURSOR_RIGHT << CURSOR_UP;
		getline(std::cin, _filename);
		std::cout << CURSOR_DOWN;

		_filename += ".bmp";

		data = Serializer::deserialize(reinterpret_cast<uintptr_t>(_filename.c_str()));
		if (data == NULL)
		{
			std::cerr << "Cannot deserialize the file." << std::endl;
		}
		else
		{
			if (Serializer::reloadTerminalData(data) == 0)
			{
				std::cerr << "Cannot load data." << std::endl;
			}
			else
			{
				bootSerialization(data);
			}
			freeTerminalData(data);
			delete data;
		}
	}

	return 0;
}
