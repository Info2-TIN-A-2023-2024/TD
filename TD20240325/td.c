#include <stdio.h>

typedef struct
{
	double x;
	double y;
} point2D;

void display_point2D(const char *name, point2D p)
{
	printf("%s={%+7.2lf,%+7.2lf }\n", name, p.x, p.y);
	return;
}

void get_center(const point2D p1, const point2D p2, point2D *pc)
{
	(*pc).x = (p1.x + p2.x) / 2.;
	(*pc).y = (p1.y + p2.y) / 2.;
	// or
	pc->x = (p1.x + p2.x) / 2.;
	pc->y = (p1.y + p2.y) / 2.;
	return;
}

int main(int argc, const char *argv[])
{
	point2D a = {13., 5.};
	point2D b = {.x = 5., .y = 10.};
	point2D c = {0., 0.};

	display_point2D("A", a);
	display_point2D("B", b);
	get_center(a, b, &c);
	display_point2D("Center", c);
	return 0;
}