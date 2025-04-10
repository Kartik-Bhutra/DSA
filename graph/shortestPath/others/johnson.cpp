#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Edge
{
  int u, v, w;
};
pair<vector<int>, vector<int>> dijkstra(int n, int src, const vector<vector<pair<int, int>>> &adj)
{
  vector<int> dist(n, INF);
  vector<int> parent(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty())
  {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue;
    for (auto [v, w] : adj[u])
    {
      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }
  return {dist, parent};
}
void printPath(int u, int v, const vector<vector<int>> &parent)
{
  if (parent[u][v] == -1)
  {
    cout << "No path from " << u << " to " << v << "\n";
    return;
  }
  vector<int> path;
  for (int cur = v; cur != -1; cur = parent[u][cur])
  {
    path.push_back(cur);
    if (cur == u)
      break;
  }
  reverse(path.begin(), path.end());
  cout << "Path from " << u << " to " << v << ": ";
  for (int node : path)
    cout << node << " ";
  cout << "\n";
}
bool johnson(int n, vector<Edge> &edges)
{
  vector<Edge> newEdges = edges;
  int q = n;
  for (int i = 0; i < n; ++i)
  {
    newEdges.push_back({q, i, 0});
  }
  vector<int> h(n + 1, INF);
  h[q] = 0;
  for (int i = 0; i < n; ++i)
  {
    for (auto &e : newEdges)
    {
      if (h[e.u] != INF && h[e.u] + e.w < h[e.v])
      {
        h[e.v] = h[e.u] + e.w;
      }
    }
  }
  for (auto &e : newEdges)
  {
    if (h[e.u] != INF && h[e.u] + e.w < h[e.v])
    {
      cout << "Graph has a negative weight cycle.\n";
      return false;
    }
  }
  vector<vector<pair<int, int>>> adj(n);
  for (auto &e : edges)
  {
    int new_w = e.w + h[e.u] - h[e.v];
    adj[e.u].push_back({e.v, new_w});
  }
  vector<vector<int>> dist(n, vector<int>(n, INF));
  vector<vector<int>> parent(n, vector<int>(n, -1));
  for (int u = 0; u < n; ++u)
  {
    auto [d, p] = dijkstra(n, u, adj);
    for (int v = 0; v < n; ++v)
    {
      if (d[v] < INF)
      {
        dist[u][v] = d[v] - h[u] + h[v];
        parent[u][v] = p[v];
      }
    }
  }
  cout << "All-Pairs Shortest Distances and Paths:\n";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (dist[i][j] == INF)
        cout << "From " << i << " to " << j << ": INF\n";
      else
      {
        cout << "From " << i << " to " << j << ": " << dist[i][j] << "\n";
        printPath(i, j, parent);
      }
    }
    cout << "\n";
  }
  return true;
}
int main()
{
  int n = 4;
  vector<Edge> edges = {
      {0, 1, -2},
      {1, 2, -1},
      {2, 3, 2},
      {3, 0, 4}};
  johnson(n, edges);
  return 0;
}
