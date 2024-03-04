#include <stdio.h>
#include <stdlib.h>




int main(int argc, const char *argv[])
{
	char *filename = "data/x.bin";
	char *mode = "wb";
	FILE *f = NULL;
	double x = 3.1415;
	unsigned char *p = (unsigned char *)&x;
	size_t i = 0;
	int num_elements = 1;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open file %s\n", filename);
		return 1;
	}

	printf("&x=%p\n", p);

	for (i = 0; i < sizeof(double); i++)
	{
		printf("%02x ", *(p+i));
	}
	puts("");

	if (num_elements != fwrite(&x, sizeof(double), num_elements, f))
	{
		printf("Error, unable to write %d elements to file %s\n", num_elements, filename);
		return 1;
	}
	if (0 != fclose(f))
	{
		printf("Error, unable to close file %s\n", filename);
		return 1;
	}

	return 0;
}