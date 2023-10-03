#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include "vertex.h"

typedef struct Array
{
  Vertex *_array;
  int _size;
  int _cap;
} Array;

void init(Array *arr, int cap);
int size(Array *arr);
void push(Array *arr, Vertex element);
Vertex get(Array *arr, int index);

#endif