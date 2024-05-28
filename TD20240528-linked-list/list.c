#include "list.h"

error_code init_list(list *l)
{
    l->first = NULL;
    l->last = NULL;
    l->num_elem = 0;
    return NO_ERROR;
}

node* create_node(const element e){
    // alloc dyn du node
    // recopie de l'element
    // init des pointeurs next et prev

    // la fonction renvoie l'adresse du node ou NULL si problème
}
