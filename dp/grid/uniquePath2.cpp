// https://leetcode.com/problems/unique-paths-ii/
#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &g)
{
  int n = g.size(), m = g[0].size();
  if (g[0][0])
    return 0;
  g[0][0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = i ? 0 : 1; j < m; j++)
    {
      if (g[i][j])
        g[i][j] = 0;
      else
      {
        if (i > 0)
          g[i][j] += g[i - 1][j];
        if (j > 0)
          g[i][j] += g[i][j - 1];
      }
    }
  }
  return g[n - 1][m - 1];
}
int main()
{
  return 0;
}