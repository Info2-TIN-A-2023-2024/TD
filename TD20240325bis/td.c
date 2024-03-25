#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct
{
	uint16_t signature;
	uint32_t size;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offset;
} bmp_header;

typedef struct
{
	uint32_t size;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bits_per_pixel;
	uint32_t compression;
	uint32_t image_size;
	int32_t x_pixels_per_meter;
	int32_t y_pixels_per_meter;
	uint32_t colors_used;
	uint32_t colors_important;
} bmp_info_header;

typedef struct
{
	uint8_t blue;
	uint8_t green;
	uint8_t red;
} pixel_color;

#pragma pack(pop)

int process_bmp_file(const char *filename)
{
	FILE *f = NULL;
	f = fopen(filename, "rb");
	if (NULL == f)
	{
		fprintf(stderr, "error while opening %s.\n", filename);
		return 1;
	}

	printf("sizeof(bmp_header)=%lu\n", sizeof(bmp_header));
	bmp_header header;
	if (1 != fread(&header, sizeof(bmp_header), 1, f))
	{
		fprintf(stderr, "error while reading bmp_header in %s.\n", filename);
		return 1;
	}
	printf("offset=%u\n", header.offset);

	bmp_info_header info_header;
	if (1 != fread(&info_header, sizeof(bmp_info_header), 1, f))
	{
		fprintf(stderr, "error while reading bmp_info_header in %s.\n", filename);
		return 1;
	}
	printf("width=%u\n", info_header.width);
	printf("height=%u\n", info_header.height);

	pixel_color *img = (pixel_color *)malloc(info_header.width * info_header.height * sizeof(pixel_color));
	if (NULL == img)
	{
		fprintf(stderr, "error while allocating memory.\n");
		return 1;
	}
	fseek(f, header.offset, SEEK_SET);
	if (info_header.width * info_header.height != fread(img, sizeof(pixel_color), info_header.width * info_header.height, f))
	{
		fprintf(stderr, "error while reading image from %s.\n", filename);
		return 1;
	}



	size_t line = 0;
	size_t column = 0;
	for (line = 0; line < info_header.height; line += 1)
	{
		for (column = 0; column < info_header.width; column += 1)
		{
			size_t index = (line * info_header.width + column);
			if (img[index].red > 128 && img[index].green <= 128 && img[index].blue <= 128)
			{
				printf("\e[1;41m "); // RED
			}
			else if (img[index].red <= 128 && img[index].green > 128 && img[index].blue <= 128)
			{
				printf("\e[1;42m "); // GREEN
			}
			else if (img[index].red <= 128 && img[index].green <= 128 && img[index].blue > 128)
			{
				printf("\e[1;44m "); // BLUE
			}
			else if (img[index].red > 127 && img[index].green > 128 && img[index].blue > 128)
			{
				printf("\e[1;47m "); // WHITE
			}
			else
			{
				printf("\e[1;40m "); // BLACK
			}
		}
		printf("\e[0m\n"); // WHITE 
	}



	free(img);
	if (fclose(f) != 0)
	{
		fprintf(stderr, "error while closing %s.\n", filename);
		return 1;
	}

	return 0;
}

int main(int argc, const char *argv[])
{

	const char *filename = "data/smile2.bmp";
	int ret = 0;

	ret = process_bmp_file(filename);
	if (ret != 0)
	{
		return ret;
	}

	return 0;
}