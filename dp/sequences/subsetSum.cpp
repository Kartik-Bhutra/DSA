// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include <bits/stdc++.h>
using namespace std;
bool isSubsetSumR(vector<int> &a, int k)
{
  int n = a.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  function<bool(int i, int s)> r = [&](int i, int s) -> bool
  {
    if (s == 0)
      return true;
    if (s < 0)
      return false;
    if (i == 0)
      return a[0] == s;
    if (dp[i][s] != -1)
      return dp[i][s];
    return dp[i][s] = (r(i - 1, s) || r(i - 1, s - a[i]));
  };
  return r(n - 1, k);
}
bool isSubsetSumI(vector<int> &a, int k)
{
  int n = a.size();
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  if (a[0] <= k)
    dp[0][a[0]] = true;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (a[i] <= j)
        dp[i][j] = dp[i][j] || dp[i - 1][j - a[i]];
    }
  }
  return dp[n - 1][k];
}
bool isSubsetSum(vector<int> &a, int k)
{
  int n = a.size();
  vector<bool> dp(k + 1, false);
  for (int i = 0; i < n; i++)
  {
    dp[0] = true;
  }
  if (a[0] <= k)
    dp[a[0]] = true;
  for (int i = 1; i < n; i++)
  {
    vector<bool> dp2(k + 1, false);
    for (int j = 0; j <= k; j++)
    {
      dp2[j] = dp[j];
      if (a[i] <= j)
        dp2[j] = dp[j] || dp[j - a[i]];
    }
    dp = dp2;
  }
  return dp[k];
}
int perfectSum(vector<int> &a, int k)
{
  int n = a.size();
  vector<int> dp(k + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = k; j >= a[i]; j--)
    {
      dp[j] += dp[j - a[i]];
    }
  }
  return dp[k];
}
int main()
{

  return 0;
}