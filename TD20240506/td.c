#include <stdio.h> // /usr/include
#include "my.h"	   // .

#define TEST
#define DEBUG 1

#define XX 6

// #error "REMOVE ME"
// #warning "CECI N'EST PAS UNE PIPE"

// #define PC
// #define PS5
#define XBOX
// #define SWITCH

#ifdef PC
#define WIDTH 640
#define HEIGHT 480
#endif
#ifdef PS5
#define WIDTH 1092
#define HEIGHT 1080
#endif
#ifdef XBOX
#define WIDTH 4096
#define HEIGHT 3072
#endif

#ifndef WIDTH
#error "No game console defined"
#endif

#if WIDTH == 640
int resol = 1;
#elif WIDTH == 1092
int resol = 2;
#elif WIDTH == 4096
int resol = 3;
#else
#warning "bad width"
#endif

int main(int argc, const char *argv[])
{
	const int X = 5;
	// printf("HELLO %d:)\n", DEBUG);
	printf("Screen size : %d x %d\n",
		   WIDTH, HEIGHT);
	return 0;
}
