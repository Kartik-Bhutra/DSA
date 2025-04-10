#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshallWithPathPrint(int n, vector<vector<int>> &graph)
{
  vector<vector<int>> dist = graph;
  vector<vector<int>> next(n, vector<int>(n, -1));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (graph[i][j] != INF)
        next[i][j] = j;
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
  auto printPath = [&](int u, int v)
  {
    if (next[u][v] == -1)
    {
      cout << "No path from " << u << " to " << v << endl;
      return;
    }
    cout << "Path from " << u << " to " << v << ": ";
    cout << u;
    while (u != v)
    {
      u = next[u][v];
      cout << " -> " << u;
    }
    cout << endl;
  };
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j && dist[i][j] < INF)
        printPath(i, j);
}

int main()
{
  int n = 4;
  vector<vector<int>> graph = {
      {0, 3, INF, 7},
      {8, 0, 2, INF},
      {5, INF, 0, 1},
      {2, INF, INF, 0}};

  floydWarshallWithPathPrint(n, graph);
  return 0;
}