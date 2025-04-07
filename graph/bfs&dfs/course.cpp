// https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int c, vector<vector<int>> &e)
{
  vector<int> adj[c];
  for (auto &pre : e)
  {
    adj[pre[1]].push_back(pre[0]);
  }
  vector<int> vis(c, 0);
  vector<int> pathVis(c, 0);
  vector<int> order;
  bool hasCycle = false;
  function<bool(int)> dfsCheck = [&](int node) -> bool
  {
    vis[node] = 1;
    pathVis[node] = 1;
    for (int neighbor : adj[node])
    {
      if (!vis[neighbor])
      {
        if (dfsCheck(neighbor))
          return true;
      }
      else if (pathVis[neighbor])
      {
        return true;
      }
    }
    pathVis[node] = 0;
    order.push_back(node);
    return false;
  };
  for (int i = 0; i < c; i++)
  {
    if (!vis[i])
    {
      if (dfsCheck(i))
        return {};
    }
  }
  reverse(order.begin(), order.end());
  return order;
}
int main()
{
  return 0;
}