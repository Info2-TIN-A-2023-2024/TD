#include "list.h"
#include <stdlib.h>
#include <string.h>

error_code init_list(list *l)
{
    l->e = (element *)realloc(NULL, (INITIAL_CAPACITY) * sizeof(element));
    if (NULL == l->e)
        return ERR_ALLOC;
    printf("init_list: l->e=%p\n", l->e);
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

bool list_is_full(const list l)
{
    return (l.capacity == l.num_elem);
}

bool list_is_empty(const list l)
{
    return (0 == l.num_elem);
}

error_code insert(list *l, const element e, const size_t position)
{
    return NO_ERROR;
}

{
    if (list_is_empty(l))
        return ERR_LIST_EMPTY;

    if (position >= l.num_elem)
        return ERR_BAD_POSITION;

    memcpy(&(l.e[position]), &e, sizeof(element));
    return NO_ERROR;
}