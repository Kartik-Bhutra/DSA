#include <bits/stdc++.h>
#include "../disjointSet/dsu.hpp"
struct Edges
{
  int u, v, wt;
};
int krushkal(vector<Edges> &e, int V)
{
  ds d(V);
  sort(e.begin(), e.end(), [](const Edges &a, const Edges &b)
       { return a.wt < b.wt; });
  int ans = 0;
  for (int i = 0; i < e.size(); i++)
  {
    int u = e[i].u, v = e[i].v, wt = e[i].wt;
    if (d.findParent(u) != d.findParent(v))
    {
      ans += wt;
      d.unionByRank(u, v);
    }
  }
  return ans;
}
vector<vector<pair<int, int>>> krushkal_(vector<Edges> &e, int V)
{
  ds d(V);
  sort(e.begin(), e.end(), [](const Edges &a, const Edges &b)
       { return a.wt < b.wt; });
  vector<vector<pair<int, int>>> ans(V);
  for (int i = 0; i < e.size(); i++)
  {
    int u = e[i].u, v = e[i].v, wt = e[i].wt;
    if (d.findParent(u) != d.findParent(v))
    {
      ans[u].push_back({v, wt});
      ans[v].push_back({u, wt});
      d.unionByRank(u, v);
    }
  }
  return ans;
}
int main()
{
  return 0;
}
