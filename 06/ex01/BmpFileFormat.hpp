#ifndef BMP_FILE_FORMAT_HPP
# define BMP_FILE_FORMAT_HPP

# include <stdint.h>

# define BITS_DEFAULT 8

#pragma pack(push, 1)
// 14 bytes
struct	BmpFileHeader
{
	uint16_t	type;		// The header field used to identify the BMP and DIB file is 0x42 0x4D in hexadecimal, same as BM in ASCII.
	uint32_t	size;		// The size of the BMP file in bytes.
	uint16_t	reserved_1;	// Reserved; actual value depends on the application that creates the image, if created manually can be 0
	uint16_t	reserved_2;	// Reserved; actual value depends on the application that creates the image, if created manually can be 0
	uint32_t	offbits;	// The offset, i.e. starting address, of the byte where the bitmap image data (pixel array) can be found.  };
};

// 40 bytes
struct	BmpInfoHeader
{
	uint32_t	size;					// the size of this header, in bytes (40)
	uint32_t	width;					// the bitmap width in pixels (signed integer)
	uint32_t	height;					// the bitmap height in pixels (signed integer)
	uint16_t	color_plane;			// the number of color planes (must be 1)
	uint16_t	bits_per_pixel;			// the number of bits per pixel, which is the color depth of the image.
	uint32_t	compression;			// the compression method being used.
	uint32_t	image_size;				// the image size. This is the size of the raw bitmap data.
	int32_t		horizontal_resolution;	// the horizontal resolution of the image. (pixel per metre, signed integer)
	int32_t		vertical_resolution;	// the vertical resolution of the image. (pixel per metre, signed integer)
	uint32_t	color_number;			// the number of colors in the color palette, or 0 to default to 2n
	uint32_t	color_number_important;	// the number of important colors used, or 0 when every color is important; generally ignored
};
#pragma pack(pop)

#endif
