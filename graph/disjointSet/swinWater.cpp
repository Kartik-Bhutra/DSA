// https://leetcode.com/problems/swim-in-rising-water/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dp[51][51][2501];
  bool vis[51][51];
  int fun(int i, int j, int maxi, vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == true)
      return INT_MAX;

    maxi = max(maxi, grid[i][j]);

    if (i == n - 1 && j == m - 1)
      return maxi;

    if (dp[i][j][maxi] != -1)
      return dp[i][j][maxi];

    vis[i][j] = true;

    int l = fun(i, j - 1, maxi, grid);
    int r = fun(i, j + 1, maxi, grid);
    int u = fun(i - 1, j, maxi, grid);
    int d = fun(i + 1, j, maxi, grid);

    vis[i][j] = false;

    return dp[i][j][maxi] = min({l, r, u, d});
  }

  int swimInWater(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    return fun(0, 0, -1, grid);
  }
};
int main()
{

  return 0;
}