// https://leetcode.com/problems/mmum-falling-path-sum/description/
#include <bits/stdc++.h>
using namespace std;
int minFallingPathSum(vector<vector<int>> &g)
{
  vector<int> dp(g.size() + 1, 0);
  for (int i = 0; i < g.size(); i++)
  {
    int t = dp[0];
    dp[g.size()] = dp[g.size() - 1];
    for (int j = 0; j < g.size(); j++)
    {
      t = min(t, min(dp[j], dp[j + 1])) + g[i][j];
      swap(dp[j], t);
    }
  }
  int m = INT_MAX;
  for (int i = 0; i < g.size(); i++)
  {
    m = min(m, dp[i]);
  }
  return m;
}
int main()
{
  return 0;
}