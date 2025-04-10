#include <bits/stdc++.h>
using namespace std;
struct Edge
{
  int u, v, w;
};
const int INF = 1e9;
void bellmanFordWithPath(int n, int source, vector<Edge> &edges)
{
  vector<int> dist(n, INF);
  vector<int> parent(n, -1);
  dist[source] = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    for (auto &e : edges)
    {
      if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
      {
        dist[e.v] = dist[e.u] + e.w;
        parent[e.v] = e.u;
      }
    }
  }
  for (auto &e : edges)
  {
    if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
    {
      cout << "Negative weight cycle detected.\n";
      return;
    }
  }
  auto printPath = [&](int v)
  {
    if (dist[v] == INF)
    {
      cout << "No path to " << v << "\n";
      return;
    }
    vector<int> path;
    for (int cur = v; cur != -1; cur = parent[cur])
      path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << "Path to " << v << " (cost " << dist[v] << "): ";
    for (int u : path)
      cout << u << " ";
    cout << "\n";
  };
  for (int v = 0; v < n; ++v)
  {
    if (v != source)
      printPath(v);
  }
}
int main()
{
  int n = 5;
  int source = 0;

  vector<Edge> edges = {
      {0, 1, 6},
      {0, 2, 7},
      {1, 2, 8},
      {1, 3, 5},
      {1, 4, -4},
      {2, 3, -3},
      {2, 4, 9},
      {3, 1, -2},
      {4, 0, 2},
      {4, 3, 7}};

  bellmanFordWithPath(n, source, edges);

  return 0;
}
