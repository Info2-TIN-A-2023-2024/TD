#include "list.h"
#include <string.h>

error_code init_list(list *l)
{
    l->first = NULL;
    l->last = NULL;
    l->num_elem = 0;
    return NO_ERROR;
}

node* create_node(const element e){
	node *new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL)
	{
		return NULL;
	}
	memcpy(&new_node->e, &e, sizeof(element));
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}
void insert_node_at_index(list *l, node *n, int index) {
	return;
}
