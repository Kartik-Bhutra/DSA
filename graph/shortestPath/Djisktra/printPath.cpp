// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
  vector<int> ans;
  vector<int> parent(n + 1);
  set<pair<int, pair<int, int>>> st;
  st.insert({0, {1, 1}});
  vector<int> vis(n + 1);
  vector<vector<vector<int>>> adj(n + 1);
  for (auto i : edges)
  {
    adj[i[0]].push_back({i[1], i[2]});
    adj[i[1]].push_back({i[0], i[2]});
  }
  while (!st.empty())
  {
    int d = st.begin()->first;
    int p = st.begin()->second.first;
    int par = st.begin()->second.second;
    st.erase(st.begin());
    if (vis[p] == 1)
      continue;
    parent[p] = par;
    if (p == n)
    {
      break;
    }
    vis[p] = 1;
    for (auto j : adj[p])
    {
      st.insert({j[1] + d, {j[0], p}});
    }
  }
  int p = n;
  while (p != 1)
  {
    ans.push_back(p);
    p = parent[p];
  }
  ans.push_back(1);
  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{

  return 0;
}