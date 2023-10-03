#ifndef NFA_H
#define NFA_H

#include <stdio.h>
#include "array.h"

typedef struct NFA
{
  int alphabetSize, statesSize, finalSize;
  int s0;
  int *final;
  Array *graph;
} NFA;

int initFromFile(NFA *nfa, FILE *file);
int processWord(NFA *nfa, char *word, int *result, int *resultSize);

#endif