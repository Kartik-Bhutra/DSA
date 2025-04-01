// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
#include <bits/stdc++.h>
using namespace std;
int minCost(int n, vector<int> &a)
{
  a.push_back(0);
  a.push_back(n);
  sort(a.begin(), a.end());
  int l = a.size();
  vector<vector<int>> dp(l, vector<int>(l, -1));
  function<int(int, int, int, int)> r = [&](int i, int j, int s, int e) -> int
  {
    if (i > j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int res = INT_MAX;
    for (int k = i; k <= j; k++)
    {
      res = min(res, r(i, k - 1, s, a[k]) +
                         r(k + 1, j, a[k], e) + (e - s));
    }
    return dp[i][j] = res;
  };
  return r(1, l - 2, 0, n);
}
int minCost(int n, vector<int> &a)
{
  int c = a.size();
  a.push_back(n);
  a.insert(a.begin(), 0);
  sort(a.begin(), a.end());
  vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
  for (int i = c; i >= 1; i--)
  {
    for (int j = 1; j <= c; j++)
    {
      if (i > j)
        continue;
      int mini = INT_MAX;
      for (int ind = i; ind <= j; ind++)
      {
        int ans = a[j + 1] - a[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
        mini = min(mini, ans);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][c];
}
int main()
{
  return 0;
}