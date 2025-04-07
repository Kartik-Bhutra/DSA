// https://leetcode.com/problems/is-graph-bipartite/description/
#include <bits/stdc++.h>
using namespace std;
bool bfs(int start, vector<vector<int>> &arr, vector<int> &vis)
{
  queue<int> q;
  q.push(start);
  vis[start] = 0;
  while (!q.empty())
  {
    int node = q.front(); 
    q.pop();
    for (auto it : arr[node])
    {
      if (vis[it] == -1)
      {
        vis[it] = !vis[node];
        q.push(it);
      }
      else if (vis[it] == vis[node])
        return false;
    }
  }
  return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
  int n = graph.size();
  vector<int> vis(n, -1);
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == -1)
    {
      if (!bfs(i, graph, vis))
        return false;
    }
  }
  return true;
}
int main()
{
  return 0;
}