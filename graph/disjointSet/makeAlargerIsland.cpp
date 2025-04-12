// https://leetcode.com/problems/making-a-large-island/
#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;
int largestIsland(vector<vector<int>> &m)
{
  int n = m.size();
  ds d(n * n);
  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (m[i][j])
      {
        int k = i * n + j;
        if (i > 0 && m[i - 1][j])
          d.unionByRank(k, k - n);
        if (j > 0 && m[i][j - 1])
          d.unionByRank(k, k - 1);
        maxi = max(maxi, d.getSize(k));
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (m[i][j] == 0)
      {
        int k = n * i + j;
        unordered_set<int> st;
        if (i > 0 && m[i - 1][j])
          st.insert(d.findParent(k - n));
        if (j > 0 && m[i][j - 1])
          st.insert(d.findParent(k - 1));
        if (i < n - 1 && m[i + 1][j])
          st.insert(d.findParent(k + n));
        if (j < n - 1 && m[i][j + 1])
          st.insert(d.findParent(k + 1));
        int sum = 0;
        for (auto t : st)
        {
          sum += d.getSize(t);
        }
        maxi = max(maxi, sum + 1);
      }
    }
  }
  return maxi;
}
class Solution
{
public:
  void dfs(vector<vector<int>> &grid,
           vector<int> &area, int i, int j, int &id)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] != 1)
      return;
    grid[i][j] = id;
    area[id]++;
    dfs(grid, area, i + 1, j, id);
    dfs(grid, area, i, j + 1, id);
    dfs(grid, area, i - 1, j, id);
    dfs(grid, area, i, j - 1, id);
  }
  int largestIsland(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size(), id = 2;
    vector<int> area(2, 0);
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          area.push_back(0);
          dfs(grid, area, i, j, id);
          id++;
        }
      }
    }
    int ans = 1, count;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          count = 1;
          int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
          if (i)
          {
            i1 = grid[i - 1][j];
            if (i1)
              count += area[i1];
          }
          if (j)
          {
            i2 = grid[i][j - 1];
            if (i2 && i2 != i1)
              count += area[i2];
          }
          if (i < m - 1)
          {
            i3 = grid[i + 1][j];
            if (i3 && i3 != i2 && i3 != i1)
              count += area[i3];
          }
          if (j < n - 1)
          {
            i4 = grid[i][j + 1];
            if (i4 && i4 != i3 && i4 != i2 && i4 != i1)
              count += area[i4];
          }
        }
        else
        {
          count = area[grid[i][j]];
        }
        ans = max(count, ans);
      }
    }
    return ans;
  }
};
int main()
{

  return 0;
}