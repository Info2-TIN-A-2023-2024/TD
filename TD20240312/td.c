#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>

void test_alloca(const size_t n) {
	double *t = NULL;
	t = (double *)alloca(n * sizeof(double));
	printf("t=%p\n", t);
	return; // WARNING: allocated memory is LOST by the end of the function
			// no need to make free(t);
}

int main(int argc, const char *argv[])
{
	size_t n = 0;
	size_t index = 0;
	double *t = NULL;

	if (argc != 2)
	{
		puts("usage: ./app\n");
		return 1;
	}
	n = atol(argv[1]);
	printf("n=%zu\n", n);

	//t = (double *)malloc(n * sizeof(double));
	t = (double *)calloc(n, sizeof(double));
	printf("t=%p\n", t);
	if(NULL==t) {
		puts("error malloc\n");
		return 1;
	}
	for (index = 0; index < n;index++) {
		printf("t[%2zu]=%+6.3lf\n", index, t[index]);
	}

	double *new_t = NULL;
	// reallonc: ALWAYS use a different pointer to store the result of realloc
	new_t = (double *)realloc(t, 3 * n * sizeof(double));
	printf("new_t=%p\n", new_t);
	if (NULL == new_t)
	{
		puts("error realloc\n");
	}
	else {
		t = new_t;
	}
	// After this point, use only the pointer t
	//.....


	// and DO NOT forget to free (t)
	free(t);

	test_alloca(n);

	return 0;
}