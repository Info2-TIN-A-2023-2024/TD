#include "queue.h"
#include <string.h>

int main(int argc, const char *argv[])
{
	list stack;
	char *s = "Il fait beau et chaud";

	init_queue(&stack);

	for (int i = 0; i < strlen(s);i++) {
		enqueue(&stack, s[i]);
	}

	for (int i = 0; i < strlen(s);i++) {
		element e = dequeue(&stack);
		printf("%c", e);
	}
	puts("");

	return 0;
}