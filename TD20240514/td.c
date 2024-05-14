#include "list.h"

int main(int argc, const char *argv[])
{
	list l;
	init_list(&l);
	display_list(l);

	element e;
	e.x = 1, e.y = 1;
	insert(&l, e, 0);
	e.x = 2, e.y = 2;
	insert(&l, e, 1);
	e.x = 3, e.y = 3;
	insert(&l, e, 2);
	e.x = 4, e.y = 4;
	insert(&l, e, 3);
	e.x = 5, e.y = 5;
	insert(&l, e, 4);
	e.x = 6, e.y = 6;
	insert(&l, e, 5);
	e.x = 7, e.y = 7;
	insert(&l, e, 6);

	display_list(l);

	delete (&l, 0);
	display_list(l);
	delete (&l, 5);
	display_list(l);

	e.x = 4;
	e.y = 4;
	int pos = search(l, e);
	printf("pos=%d\n", pos);
	e.x = 40;
	e.y = 40;
	pos = search(l, e);
	printf("pos=%d\n", pos);
	return 0;
}