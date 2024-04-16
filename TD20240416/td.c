#include <stdio.h> //    /usr/include

#include "cplx.h"  //    .

int main(int argc, const char *argv[])
{
	cplx c1;

	init_cplx(&c1);

	c1.real = 4.;
	c1.img = 3.;
	puts("c1");
	display_cplx(c1);

	cplx c2 = conjugue(c1);
	puts("c2");
	display_cplx(c2);

	printf("||c1||=%+8.3lf\n", norm(c1));
	printf("||c2||=%+8.3lf\n", norm(c2));

	printf("arg(c1)=%+8.3lf\n", arg(c1));
	printf("arg(c2)=%+8.3lf\n", arg(c2));

	cplx c3;
	c3 = pol2cart(norm(c1), arg(c1));
	puts("c3");
	display_cplx(c3);


	return 0;
}
 