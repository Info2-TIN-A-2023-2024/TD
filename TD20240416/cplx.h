#pragma once

typedef struct {
    double real;
    double img;
} cplx;

void init_cplx(cplx *p);
void display_cplx(const cplx c);
cplx conjugue(cplx c);
double norm(const cplx c);
double arg(const cplx c); // result in radians
cplx pol2cart(const double rho, const double theta);
