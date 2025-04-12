#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<vector<pair<int, int>>> primMST(const vector<vector<pair<int, int>>> &adj)
{
  int n = adj.size();
  vector<int> key(n, INF);
  vector<int> parent(n, -1);
  vector<bool> inMST(n, false);
  set<pair<int, int>> pq;
  key[0] = 0;
  pq.insert({0, 0});
  while (!pq.empty())
  {
    int u = pq.begin()->second;
    pq.erase(pq.begin());
    inMST[u] = true;
    for (auto [v, weight] : adj[u])
    {
      if (!inMST[v] && weight < key[v])
      {
        pq.erase({key[v], v});
        key[v] = weight;
        parent[v] = u;
        pq.insert({key[v], v});
      }
    }
  }
  vector<vector<pair<int, int>>> mst(n);
  for (int v = 1; v < n; ++v)
  {
    int u = parent[v];
    if (u != -1)
    {
      mst[u].push_back({v, key[v]});
      mst[v].push_back({u, key[v]});
    }
  }
  return mst;
}
void printMSTTree(const vector<vector<pair<int, int>>> &mst)
{
  cout << "Minimum Spanning Tree (as tree structure):\n";
  for (int u = 0; u < mst.size(); ++u)
  {
    for (auto [v, wt] : mst[u])
    {
      if (u < v)
        cout << u << " -- " << v << " [Weight: " << wt << "]\n";
    }
  }
}
int spanningTree(int V, vector<vector<int>> adj[])
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(V, 0);
  pq.push({0, 0});
  int sum = 0;
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int node = it.second;
    int wt = it.first;
    if (vis[node] == 1)
      continue;
    vis[node] = 1;
    sum += wt;
    for (auto it : adj[node])
    {
      int adjNode = it[0];
      int edW = it[1];
      if (!vis[adjNode])
      {
        pq.push({edW, adjNode});
      }
    }
  }
  return sum;
}
int main()
{
  vector<vector<pair<int, int>>> adj = {
      {{1, 2}, {3, 6}},
      {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
      {{1, 3}, {4, 7}},
      {{0, 6}, {1, 8}},
      {{1, 5}, {2, 7}}};
  auto mst = primMST(adj);
  printMSTTree(mst);
  return 0;
}
