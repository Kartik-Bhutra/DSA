// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;
int makeConnected(int n, vector<vector<int>> &c)
{
  ds d(n);
  int k = c.size();
  int rem = 0;
  for (int i = 0; i < k; i++)
  {
    int u = c[i][0], v = c[i][1];
    if (d.findParent(u) == d.findParent(v))
    {
      rem++;
    }
    else
    {
      d.unionByRank(u, v);
    }
  }
  int ult = 0, ans = 0;
  for (int i = 1; i < n; i++)
  {
    if (d.findParent(ult) != d.findParent(i))
    {
      if (rem == 0)
        return -1;
      rem--;
      ans++;
      d.unionByRank(ult, i);
    }
  }
  return ans;
}
class Solution
{
public:
  vector<int> parent;
  vector<int> rank;
  int findparent(int i)
  {
    if (i == parent[i])
    {
      return i;
    }
    return parent[i] = findparent(parent[i]);
  }
  void findunion(int x_parent, int y_parent)
  {
    x_parent = findparent(x_parent);
    y_parent = findparent(y_parent);

    if (x_parent == y_parent)
      return;

    if (rank[x_parent] > rank[y_parent])
    {
      parent[y_parent] = x_parent;
    }
    else if (rank[x_parent] < rank[y_parent])
    {
      parent[x_parent] = y_parent;
    }
    else
    {
      parent[y_parent] = x_parent;
      rank[x_parent]++;
    }
  }
  int makeConnected(int n, vector<vector<int>> &connections)
  {
    if (n - 1 > connections.size())
      return -1;
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
    for (auto &vec : connections)
    {
      if (findparent(vec[0]) != findparent(vec[1]))
      {
        findunion(vec[0], vec[1]);
        n--;
      }
    }
    return n - 1;
  }
};
int main()
{

  return 0;
}