#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int process_bmp_file(const char *filename)
{
	FILE *f = NULL;
	int ret = 0;
	f = fopen(filename, "rb");
	if (NULL == f)
	{
		fprintf(stderr, "error while opening %s.\n", filename);
		return 1;
	}

	fseek(f, 10, SEEK_SET);
	uint32_t file_offset = 0;
	ret = fread(&file_offset, sizeof(uint32_t), 1, f);
	if (1 != ret)
	{
		fprintf(stderr, "error while reading header in %s.\n", filename);
		return 1;
	}
	printf("file_offset=%u\n", file_offset);

	fseek(f, 4, SEEK_CUR);
	uint32_t width = 0;
	uint32_t height = 0;
	ret = fread(&width, sizeof(uint32_t), 1, f);
	if (1 != ret)
	{
		fprintf(stderr, "error while reading width in %s.\n", filename);
		return 1;
	}
	ret = fread(&height, sizeof(uint32_t), 1, f);
	if (1 != ret)
	{
		fprintf(stderr, "error while reading height in %s.\n", filename);
		return 1;
	}
	printf("width=%u\n", width);
	printf("height=%u\n", height);

	uint16_t planes = 0;
	uint16_t bits_per_pixel = 0;
	ret = fread(&planes, sizeof(uint16_t), 1, f);
	if (1 != ret)
	{
		fprintf(stderr, "error while reading planes in %s.\n", filename);
		return 1;
	}
	ret = fread(&bits_per_pixel, sizeof(uint16_t), 1, f);
	if (1 != ret)
	{
		fprintf(stderr, "error while reading bits_per_pixels in %s.\n", filename);
		return 1;
	}
	printf("planes=%u\n", planes);
	printf("bits_per_pixels=%u\n", bits_per_pixel);

	unsigned char *img = NULL;
	size_t memory_size = width * height * planes * bits_per_pixel / 8;
	img = (unsigned char *)malloc(memory_size*sizeof(unsigned char));
	if (NULL==img)
	{
		fprintf(stderr, "error while allocating %zu bytes.\n", memory_size);
		return 1;
	}

	ret=fread(img, sizeof(unsigned char), memory_size, f);
	if (memory_size != ret)
	{
		fprintf(stderr, "error while reading data from %s.\n", filename);
		free(img);
		return 1;
	}

	size_t line = 0;
	size_t column = 0;
	for (line = 0; line < height;line++) {

		for (column = 0; column < width; column++) {

			size_t index = (width * line + column) * bits_per_pixel / 8;

			putchar(img[index] < 128 ? ' ' : '*');
		}
		putchar('\n'); // puts(""); // printf("\n");
	}

		if (fclose(f) != 0)
		{
			fprintf(stderr, "error while closing %s.\n", filename);
			return 1;
		}
	free(img);

	return 0;
}

int main(int argc, const char *argv[])
{

	const char *filename = "data/smile.bmp";
	int ret = 0;

	ret = process_bmp_file(filename);
	if (ret != 0)
	{
		return ret;
	}

	return 0;
}