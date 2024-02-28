// files and directories organisation
// file types (text, binary)
// filename and path (relative, absolute)
// file access modes (read, write, append)
// access mechanisms (open, close, read, write, seek, tell)
// always check errors

#include <stdio.h>
#include <stdlib.h>

double my_rand(double min, double max)
{
	return min + (max - min) * rand() / (double)RAND_MAX;
}

int create_file(const char *filename)
{

	const size_t NUM_LINES = 20000;
	const char *mode = "w";
	FILE *f = NULL;
	size_t index = 0;
	double x = 0.;
	double y = 0.;
	double sum_x = 0.;
	double sum_y = 0.;
	double mean_x = 0.;
	double mean_y = 0.;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to create file %s\n", filename);
		return 1;
	}
	// printf("f=%p\n", f);
	for (index = 0; index < NUM_LINES; index++)
	{
		x = my_rand(-1.0, +1.0);
		y = my_rand(-1.0, +1.0);
		sum_x += x;
		sum_y += y;
		fprintf(f, "%+6.3lf %+6.3lf\n",
				x, y);
	}

	mean_x = sum_x / NUM_LINES;
	mean_y = sum_y / NUM_LINES;
	printf("mean_x=%+.15lf mean_y=%+.15lf\n", mean_x, mean_y);

	if (0 != fclose(f))
	{
		printf("Error, unable to close file %s\n", filename);
		return 1;
	}
	return 0;
}

int process_file(const char *filename)
{
	const char *mode = "r";
	FILE *f = NULL;
	int ret = 0;

	size_t num_lines = 0;
	double x = 0.;
	double y = 0.;
	double sum_x = 0.;
	double sum_y = 0.;
	double mean_x = 0.;
	double mean_y = 0.;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open file %s\n", filename);
		return 1;
	}

	do
	{
		ret = fscanf(f, "%lf %lf", &x, &y);
		if (!feof(f))
		{
			if (2 != ret)
			{
				printf("Error, unable to read 2 values from file %s\n", filename);
				return 1;
			}
			sum_x += x;
			sum_y += y;
			num_lines++;
		}
	} while (!feof(f));

	printf("num_lines=%ld\n", num_lines);
	mean_x = sum_x / num_lines;
	mean_y = sum_y / num_lines;
	printf("mean_x=%+.15lf mean_y=%+.15lf\n", mean_x, mean_y);

	if (0 != fclose(f))
	{
		printf("Error, unable to close file %s\n", filename);
		return 1;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.txt";
	srand(0);

	if (0 != create_file(filename))
	{
		printf("Error, unable to create file %s\n", filename);
		return 1;
	}
	if (0 != process_file(filename))
	{
		printf("Error, unable to process file %s\n", filename);
		return 1;
	}
	return 0;
}