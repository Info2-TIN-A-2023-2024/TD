#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "error_code.h"

#define INITIAL_CAPACITY 5

typedef struct {
    double x;
    double y;
} point2D;

typedef point2D element;

typedef struct {

    element *e;
    size_t capacity;
    size_t num_elem;

} list;

error_code init_list(list *l);
void display_list(const list l);
bool list_is_full(list l);
error_code insert(list *l, element e, size_t position);