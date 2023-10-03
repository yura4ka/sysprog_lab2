#include <stdio.h>
#include <string.h>
#include "array.h"
#include "nfa.h"

void dfs(Array *adj, int node, int *visited)
{
  visited[node] = 1;
  for (int i = 0; i < size(&adj[node]); i++)
  {
    int toVisit = get(&adj[node], i).state;
    if (!visited[toVisit])
      dfs(adj, toVisit, visited);
  }
}

Array *reverseDirection(Array *adj, int n)
{
  Array *result = (Array *)malloc(n * sizeof(Array));
  for (int i = 0; i < n; i++)
    init(&result[i], 0);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < size(&adj[i]); j++)
    {
      Vertex v = get(&adj[i], j);
      push(&result[v.state], (Vertex){i, v.symbol});
    }
  }

  return result;
}

void printNonVisited(int *visited, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
      printf("%d ", i);
  }
  printf("\n");
}

int main()
{
  FILE *file = fopen("text.txt", "r");
  NFA nfa;

  if (file == NULL)
  {
    printf("File not found!\n");
    return 0;
  }

  initFromFile(&nfa, file);

  fclose(file);

  int visited[nfa.statesSize];
  memset(visited, 0, sizeof(int) * nfa.statesSize);

  dfs(nfa.graph, nfa.s0, visited);

  printf("Unreachable: ");
  printNonVisited(visited, nfa.statesSize);

  Array *reversed = reverseDirection(nfa.graph, nfa.statesSize);
  memset(visited, 0, sizeof(int) * nfa.statesSize);
  for (int i = 0; i < nfa.finalSize; i++)
  {
    if (!visited[nfa.final[i]])
      dfs(reversed, nfa.final[i], visited);
  }

  printf("Dead-end: ");
  printNonVisited(visited, nfa.statesSize);

  char word[100];
  while (1)
  {
    printf("Enter word (press 'q' to exit): ");
    if (scanf("%99s", word) != 1)
    {
      printf("Error, try again!\n");
      continue;
    }

    if (strcmp(word, "q") == 0)
      break;

    int resultSize = 0, result[101];
    int status = processWord(&nfa, word, result, &resultSize);

    if (status == 1)
      printf("Edge not found!: ");
    else if (status == 2)
      printf("Word not proccessed!: ");
    else
      printf("Result: ");

    for (int i = 0; i < resultSize; i++)
      printf("%d ", result[i]);
    printf("\n");
  }

  return 0;
}