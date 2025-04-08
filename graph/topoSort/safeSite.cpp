// https://leetcode.com/problems/find-eventual-safe-states/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>> &adj)
{
  int n = adj.size();
  vector<int> out(n);
  vector<bool> val(n), vis(n, false);
  for (int i = 0; i < n; i++)
  {
    out[i] = adj[i].size();
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (out[i] == 0)
    {
      val[i] = true;
      ans.push_back(i);
    }
  }
  function<bool(int)> r = [&](int i) -> int
  {
    if (vis[i])
      return val[i];
    vis[i] = true;
    bool v = 1;
    for (auto x : adj[i])
    {
      v = v & r(x);
    }
    if (v)
      ans.push_back(i);
    return val[i] = v;
  };
  for (int i = 0; i < n; i++)
  {
    r(i);
  }
  return ans;
}
int main()
{

  return 0;
}