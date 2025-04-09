//
#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
  vector<vector<pair<int, int>>> adj(n);
  for (auto &f : flights)
  {
    adj[f[0]].emplace_back(f[1], f[2]);
  }
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  int stops = -1;
  queue<pair<int, int>> q;
  q.emplace(src, 0);
  while (!q.empty() && stops < k)
  {
    int breadth = q.size();
    while (breadth--)
    {
      auto [u, d] = q.front();
      q.pop();
      for (auto &[v, w] : adj[u])
      {
        if (d + w < dist[v])
        {
          dist[v] = d + w;
          q.emplace(v, dist[v]);
        }
      }
    }
    ++stops;
  }
  return dist[dst] == INT_MAX ? -1 : dist[dst];
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
  vector<pair<int, int>> adj[n];
  for (auto it : flights)
  {
    adj[it[0]].push_back({it[1], it[2]});
  }
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {src, 0}});
  vector<int> dist(n, 1e9);
  dist[src] = 0;
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int stops = it.first;
    int node = it.second.first;
    int cost = it.second.second;
    for (auto iter : adj[node])
    {
      int adjNode = iter.first;
      int edW = iter.second;
      if (cost + edW < dist[adjNode] && stops <= K)
      {
        dist[adjNode] = cost + edW;
        q.push({stops + 1, {adjNode, cost + edW}});
      }
    }
  }
  if (dist[dst] == 1e9)
    return -1;
  return dist[dst];
}
int main()
{
  return 0;
}