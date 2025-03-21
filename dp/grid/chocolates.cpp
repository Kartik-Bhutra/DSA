// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
#include <bits/stdc++.h>
using namespace std;
int solveR(int m, int n, vector<vector<int>> &g)
{
  vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
  function<int(int, int, int)> r = [&](int i, int j, int k) -> int
  {
    if (i == m || j < 0 || j >= n || k < 0 || k >= n)
    {
      return 0;
    }
    if (dp[i][j][k] != -1)
      return dp[i][j][k];
    int s = (j == k) ? g[i][j] : g[i][j] + g[i][k];
    int m = 0;
    for (int dj = -1; dj <= 1; dj++)
    {
      for (int dk = -1; dk <= 1; dk++)
      {
        m = max(m, r(i + 1, j + dj, k + dk));
      }
    }
    return dp[i][j][k] = s + m;
  };
  return r(0, 0, n - 1);
}
int solveI(int m, int n, vector<vector<int>> &g)
{
  vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        dp[m - 1][i][j] = g[m - 1][i];
      }
      else
      {
        dp[m - 1][i][j] = g[m - 1][i] + g[m - 1][j];
      }
    }
  }
  for (int i = m - 2; i >= 0; i--)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        int s;
        if (k == j)
        {
          s = g[i][k];
        }
        else
        {
          s = g[i][k] + g[i][j];
        }
        for (int dj = -1; dj <= 1; dj++)
        {
          for (int dk = -1; dk <= 1; dk++)
          {
            int x = j + dj, y = k + dk;
            if (x >= n || x < 0 || y >= n || y < 0)
              continue;
            dp[i][j][k] = max(dp[i + 1][x][y] + s, dp[i][j][k]);
          }
        }
      }
    }
  }
  return dp[0][0][n - 1];
}
int solve(int m, int n, vector<vector<int>> &g)
{
  vector<vector<int>> dp(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        dp[i][j] = g[m - 1][i];
      }
      else
      {
        dp[i][j] = g[m - 1][i] + g[m - 1][j];
      }
    }
  }
  for (int i = m - 2; i >= 0; i--)
  {
    vector<vector<int>> dp2(n, vector<int>(n, -1));
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        int s;
        if (k == j)
        {
          s = g[i][k];
        }
        else
        {
          s = g[i][k] + g[i][j];
        }
        for (int dj = -1; dj <= 1; dj++)
        {
          for (int dk = -1; dk <= 1; dk++)
          {
            int x = j + dj, y = k + dk;
            if (x >= n || x < 0 || y >= n || y < 0)
              continue;
            dp2[j][k] = max(dp[x][y] + s, dp2[j][k]);
          }
        }
      }
    }
    dp = dp2;
  }
  return dp[0][n - 1];
}
int main()
{
  vector<vector<int>> g = {
      {3, 1, 1},
      {2, 5, 1},
      {1, 5, 5},
      {2, 1, 1}};
  int m = g.size();
  int n = g[0].size();
  cout << "Maximum chocolates collected: " << solve(m, n, g) << endl;
  return 0;
}