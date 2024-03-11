#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE -1.
#define MAX_VALUE 1.

double my_rand(const double val_min, const double val_max)
{
	return val_min + (val_max - val_min) * (rand() / (double)RAND_MAX);
}

int create_file(const char *filename, const size_t num_points)
{
	FILE *f = NULL;

	srand(0);

	f = fopen(filename, "wb");
	if (NULL == f)
	{
		fprintf(stderr, "error while opening %s.\n", filename);
		return 1;
	}

	char c = 'd';

	if (1 != fwrite(&c, sizeof(char), 1, f))
	{
		fprintf(stderr, "error while writing header %s.\n", filename);
		return 1;
	}

	if (1 != fwrite(&num_points, sizeof(size_t), 1, f))
	{
		fprintf(stderr, "error while writing header %s.\n", filename);
		return 1;
	}

	double x = 0.;
	double y = 0.;
	size_t index = 0;

	for (index = 0; index < num_points; index++)
	{
		x = my_rand(MIN_VALUE, MAX_VALUE);
		y = my_rand(MIN_VALUE, MAX_VALUE);
		if (1 != fwrite(&x, sizeof(double), 1, f))
		{
			fprintf(stderr, "error while writing x data %s.\n", filename);
			return 1;
		}
		if (1 != fwrite(&y, sizeof(double), 1, f))
		{
			fprintf(stderr, "error while writing y data %s.\n", filename);
			return 1;
		}
	}

	if (0 != fclose(f))
	{
		fprintf(stderr, "error while closing %s.\n", filename);
		return 1;
	}
	return 0;
}

int process_file(const char *filename)
{
	FILE *f = NULL;

	f = fopen(filename, "rb");
	if (NULL == f)
	{
		fprintf(stderr, "error while opening %s.\n", filename);
		return 1;
	}

	char c = 0;
	size_t num_elem = 0;

	if (1 != fread(&c, sizeof(char), 1, f))
	{
		fprintf(stderr, "error while reading the header %s.\n", filename);
		return 1;
	}
	if (c != 'd')
	{
		fprintf(stderr, "bad header in %s.\n", filename);
		return 1;
	}
	if (1 != fread(&num_elem, sizeof(size_t), 1, f))
	{
		fprintf(stderr, "error while reading the header %s.\n", filename);
		return 1;
	}
	printf("num_elem=%ld\n", num_elem);

	size_t index = 0;
	double x = 0.;
	double y = 0.;
	double sum_x = 0.;
	double sum_y = 0.;
	double mean_x = 0.;
	double mean_y = 0.;

	for (index = 0; index < num_elem; index++)
	{
		if(1!=fread(&x, sizeof(double), 1, f)) {
			fprintf(stderr, "error while reading x %s.\n", filename);
			return 1;
		}
		if (1 != fread(&y, sizeof(double), 1, f))
		{
			fprintf(stderr, "error while reading y %s.\n", filename);
			return 1;
		}
		sum_x += x;
		sum_y += y;
	}

	mean_x = sum_x / num_elem;
	mean_y = sum_y / num_elem;
	printf("mean_x=%+.15lf\n", mean_x);
	printf("mean_y=%+.15lf\n", mean_y);
	
	if (0 != fclose(f))
	{
		fprintf(stderr, "error while closing %s.\n", filename);
		return 1;
	}
	return 0;
}

int main(int argc, const char *argv[])
{

	const char *filename = "data/data.bin";
	int ret = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <num_points>\n", argv[0]);
		return 1;
	}

	const size_t num_points = atol(argv[1]);

	ret = create_file(filename, num_points);
	if (ret != 0)
	{
		return ret;
	}

	ret = process_file(filename);
	if (ret != 0)
	{
		return ret;
	}

	return 0;
}