#include "stack.h"

int main(int argc, const char *argv[])
{
	list stack;
	init_stack(&stack);

	element e;
	e.x = 1., e.y = -1;
	push(&stack, e);

	e.x = 2., e.y = -2;
	push(&stack, e);

	e = pop(&stack);
	printf("e: %lf, %lf", e.x, e.y); // 2 , -2

	return 0;
}