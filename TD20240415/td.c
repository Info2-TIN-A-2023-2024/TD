#include <stdio.h>
#include <math.h>

#define NMAX (10+10)

int main(int argc, const char *argv[])
{
	char t[NMAX];
	for (size_t i = 0; i < NMAX; i++)
	{
		t[i] = 'A' + i;
		printf("%lf\n", sin(i));
	}
	return 0;
}
