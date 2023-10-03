#include "array.h"
#include "vertex.h"

void init(Array *arr, int cap)
{
  if (cap <= 0)
    cap = 0;
  arr->_cap = cap;
  arr->_size = 0;
  arr->_array = (Vertex *)malloc(cap * sizeof(Vertex));
}

int size(Array *arr)
{
  return arr->_size;
}

void push(Array *arr, Vertex element)
{
  if (arr->_size == arr->_cap)
  {
    arr->_cap = (arr->_cap + 1) * 2;
    arr->_array = realloc(arr->_array, arr->_cap * sizeof(int));
  }
  arr->_array[arr->_size++] = element;
}

Vertex get(Array *arr, int index)
{
  return arr->_array[index];
}
