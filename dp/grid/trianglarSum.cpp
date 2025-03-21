// https://leetcode.com/problems/triangle/description/
#include <bits/stdc++.h>
using namespace std;
int minimumTotal(vector<vector<int>> &arr)
{
  vector<int> dp(arr.size(), INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    int t = dp[0];
    for (int j = 0; j <= i; j++)
    {
      t = min(dp[j], t) + arr[i][j];
      swap(t, dp[j]);
    }
  }
  int mini = INT_MAX;
  for (int i = 0; i < arr.size(); i++)
  {
    mini = min(mini, dp[i]);
  }
  return mini;
}
int main()
{
  return 0;
}