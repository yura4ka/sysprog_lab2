#include <stdio.h>
#include <string.h>
#include "nfa.h"

int initFromFile(NFA *nfa, FILE *file)
{
  fscanf(file, "%d%d%d%d",
         &nfa->alphabetSize, &nfa->statesSize, &nfa->s0, &nfa->finalSize);

  nfa->final = (int *)malloc(nfa->finalSize * sizeof(int));
  for (int i = 0; i < nfa->finalSize; i++)
    fscanf(file, "%d", &nfa->final[i]);

  nfa->graph = (Array *)malloc(nfa->statesSize * sizeof(Array));
  for (int i = 0; i < nfa->statesSize; i++)
    init(&nfa->graph[i], 0);

  int s1, s2;
  char c;
  while (1)
  {
    if (fscanf(file, "%d %c %d", &s1, &c, &s2) != 3)
      break;
    Vertex v = {s2, c};
    push(&nfa->graph[s1], v);
  }
}

int processWord(NFA *nfa, char *word, int *result, int *resultSize)
{
  int len = strlen(word);
  int s = nfa->s0;
  int hasFind;
  result[(*resultSize)++] = s;

  for (int i = 0; i < len; i++)
  {
    hasFind = 0;
    for (int j = 0; j < size(&nfa->graph[s]); j++)
    {
      Vertex v = get(&nfa->graph[s], j);
      if (word[i] == v.symbol)
      {
        s = v.state;
        hasFind = 1;
        break;
      }
    }
    if (!hasFind)
      return 1;

    result[(*resultSize)++] = s;
    for (int j = 0; j < nfa->finalSize; j++)
      if (nfa->final[j] == s)
        return 0;
  }

  return 2;
}