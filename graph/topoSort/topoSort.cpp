// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int v, vector<vector<int>> &e)
{
  vector<vector<int>> adj(v);
  for (auto &p : e)
  {
    adj[p[0]].push_back(p[1]);
  }
  vector<bool> vis(v, 0);
  stack<int> st;
  function<void(int)> r = [&](int i)
  {
    if (vis[i] == true)
      return;
    vis[i] = true;
    for (auto x : adj[i])
    {
      r(x);
    }
    st.push(i);
  };
  for (int i = 0; i < v; i++)
  {
    if (vis[i] == false)
      r(i);
  }
  vector<int> ans;
  while (st.size())
  {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}
vector<int> topoSort(int V, vector<int> adj[])
{
  int indegree[V] = {0};
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < V; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  vector<int> topo;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
        q.push(it);
    }
  }
  return topo;
}
int main()
{
  return 0;
}