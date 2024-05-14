#include "list.h"

int main(int argc, const char *argv[])
{
	list l;
	init_list(&l);
	display_list(l);

	element e;
	e.x = 1, e.y = 1;
	insert(&l, e, 0);
	display_list(l);
	return 0;
}