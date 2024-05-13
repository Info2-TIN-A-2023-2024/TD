#include "list.h"
#include <stdlib.h>

error_code init_list(list *l)
{

    l->e = (element *)malloc(INITIAL_CAPACITY * sizeof(element));
    if (NULL == l->e)
        return ERR_ALLOC;
    l->capacity = INITIAL_CAPACITY;
    l->num_elem = 0;
    return NO_ERROR;
}

void display_list(const list l)
{
    printf("capacity=%zu\n", l.capacity);
    printf("num_elem=%zu\n", l.num_elem);
    for (size_t index = 0; index < l.num_elem; index++)
    {
        printf("%3zu (%+8.3lf,%+8.3lf)\n",
               index, l.e[index].x, l.e[index].y);
    }
}

bool list_is_full(list l)
{
    return (l.capacity == l.num_elem);
}

error_code insert(list *l, element e, size_t position)
{
    if(list_is_full(*l))
        return ERR_LIST_FULL;

    // TODO: implementation of the insertion
}