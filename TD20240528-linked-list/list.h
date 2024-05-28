#pragma once
#include <stdio.h>
#include "error_code.h"

typedef struct {
    double x;
    double y;
} point2D;

typedef point2D element;

typedef struct node {
    element e;
    struct node *prev;
    struct node *next;
} node;

typedef struct {
    node *first;
    node *last;
    size_t num_elem;
} list;