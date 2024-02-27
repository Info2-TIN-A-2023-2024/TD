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

int main(int argc, const char *argv[])
{
	const size_t NUM_LINES = 5;
	const char *filename = "./data/data.txt";
	const char *mode = "w";
	FILE *f = NULL;
	size_t index = 0;
	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to create file %s\n", filename);
		return 1;
	}
	// printf("f=%p\n", f);
	for (index = 0; index < NUM_LINES; index++)
	{
		printf("%+6.3lf %+6.3lf\n",
			   my_rand(-1.0, +1.0), my_rand(-1.0, +1.0));
	}

	if (0 != fclose(f))
	{
		printf("Error, unable to close file %s\n", filename);
		return 1;
	}
	return 0;
}