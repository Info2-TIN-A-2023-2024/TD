#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	const double a = -1.;
	const double b = -2.;
	const double c = 3.;

	double delta = 0.;
	double x1 = 0.;
	double x2 = 0.;

#if DEBUG == 2
	printf("a=%+8.3lf\n", a);
	printf("b=%+8.3lf\n", b);
	printf("c=%+8.3lf\n", c);
#endif

	delta = b * b - 4. * a * c;
#if DEBUG >0
	printf("∆=%+8.3lf\n", delta);
#endif


	if (delta >= 0)
	{
		x1 = (-b + sqrt(delta)) / 2. / a;
		x2 = (-b - sqrt(delta)) / 2. / a;
		printf("x1=%+8.3lf\n", x1);
		printf("x2=%+8.3lf\n", x2);
	}
	else
	{
		puts("imagination...");
	}
	return 0;
}
