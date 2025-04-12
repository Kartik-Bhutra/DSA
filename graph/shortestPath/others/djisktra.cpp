#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
pair<vector<int>, vector<int>> dijkstra_dense(int n, int src, const vector<vector<int>> &graph)
{
  vector<int> dist(n, INF);
  vector<int> parent(n, -1);
  vector<bool> visited(n, false);
  dist[src] = 0;
  for (int i = 0; i < n; ++i)
  {
    int u = -1;
    for (int j = 0; j < n; ++j)
    {
      if (!visited[j] && (u == -1 || dist[j] < dist[u]))
      {
        u = j;
      }
    }
    if (dist[u] == INF)
      break;
    visited[u] = true;
    for (int v = 0; v < n; ++v)
    {
      if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }
  return {dist, parent};
}
void printPath(int src, int v, const vector<int> &parent)
{
  if (v == src)
  {
    cout << src << " ";
    return;
  }
  if (parent[v] == -1)
  {
    cout << "No path";
    return;
  }
  printPath(src, parent[v], parent);
  cout << v << " ";
}
int main()
{
  int n = 4;
  vector<vector<int>> graph = {
      {0, 2, 5, INF},
      {2, 0, 1, 3},
      {5, 1, 0, 2},
      {INF, 3, 2, 0}};
  int src = 0;
  auto [dist, parent] = dijkstra_dense(n, src, graph);
  cout << "Shortest distances and paths from node " << src << ":\n";
  for (int i = 0; i < n; ++i)
  {
    cout << "To " << i << ": ";
    if (dist[i] == INF)
    {
      cout << "INF (No path)\n";
    }
    else
    {
      cout << "Distance = " << dist[i] << ", Path = ";
      printPath(src, i, parent);
      cout << "\n";
    }
  }
  return 0;
}
