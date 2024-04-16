#include <stdio.h>
#include <math.h>
#include "cplx.h"

void init_cplx(cplx *p) {
    p->real = 0.;
    p->img = 0.; // (*p).img=0.;
    return;
}

void display_cplx(const cplx c) {
	printf(".real = %+8.3lf\n", c.real);
	printf(".img  = %+8.3lf\n", c.img);
    return;
}

cplx conjugue(cplx c) {
    c.img *= -1.;
    return c;
}

double norm(const cplx c) {
    double n = sqrt( c.img*c.img + c.real*c.real);
    return n;
}

double arg(const cplx c) {
    double a = atan2(c.img, c.real);
    return a;
}

cplx pol2cart(const double rho, const double theta) {
    cplx c;
    c.real = rho * cos(theta);
    c.img = rho * sin(theta);
    return c;
}