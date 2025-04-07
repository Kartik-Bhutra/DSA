// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;
bool isCycle(int v, vector<vector<int>> &e)
{
  int n = e.size();
  vector<vector<int>> adj(v);
  for (int i = 0; i < n; i++)
  {
    int u = e[i][0], k = e[i][1];
    adj[u].push_back(k);
    adj[k].push_back(u);
  }
  vector<bool> vis(v, 0);
  function<bool(int, int)> r = [&](int i, int p) -> bool
  {
    vis[i] = 1;
    bool v = false;
    for (int j = 0; j < adj[i].size(); j++)
    {
      int k = adj[i][j];
      if (vis[k] && k != p)
        return true;
      if (vis[k] == 0)
      {
        v = v | r(k, i);
      }
      if (v)
        return true;
    }
    return false;
  };
  for (int i = 0; i < v; i++)
  {
    if (vis[i] == 0)
    {
      if (r(i, -1))
        return true;
    }
  }
  return false;
}
bool detect(int src, vector<int> adj[], int vis[])
{
  vis[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for (auto adjacentNode : adj[node])
    {
      if (!vis[adjacentNode])
      {
        vis[adjacentNode] = 1;
        q.push({adjacentNode, node});
      }
      else if (parent != adjacentNode)
      {
        return true;
      }
    }
  }
  return false;
}
bool isCycle(int V, vector<int> adj[])
{
  int vis[V] = {0};
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      if (detect(i, adj, vis))
        return true;
    }
  }
  return false;
}
int main()
{

  return 0;
}