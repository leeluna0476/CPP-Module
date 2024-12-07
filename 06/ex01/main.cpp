#include "Serializer.hpp"
#include <iostream>
#include <unistd.h>

int	main(void)
{
	// serialize
	std::cout << CLEAR_SCREEN;

	Data*	data = Serializer::generateImgData();
	if (data == NULL)
	{
		std::cerr << "Failed to generate image data." << std::endl;
		return 0;
	}

	for (;;)
	{
		uintptr_t	i_ptr = Serializer::serialize(data);
		if (data->magic_number == 0x4A53)
		{
			Data*	_data = Serializer::deserialize(i_ptr);
			if (_data == data)
			{
//				밀당용 코드
//				std::cout << CLEAR_SCREEN;
//				for (uint32_t i = 0; i < 3; i++)
//				{
//					std::cout << "...reloading drafted data..." << std::endl;
//					usleep(1000000);
//				}

				Serializer::reloadTerminalData(_data);
			}
			else
			{
				std::cerr << "Failed to deserialize the data." << std::endl;
				break;
			}
		}
		else
		{
			break;
		}
	}

	return 0;
}
