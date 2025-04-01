// https://leetcode.com/problems/burst-balloons/
#include <bits/stdc++.h>
using namespace std;
int maxCoins(vector<int> &a)
{
  a.push_back(1);
  a.insert(a.begin(), 1);
  int N = a.size();
  vector<vector<int>> dp(N, vector<int>(N, 0));

  for (int len = 1; len < N - 1; len++)
  {
    for (int i = 1; i < N - len; i++)
    {
      int j = i + len - 1;
      for (int k = i; k <= j; k++)
      {
        int coins = dp[i][k - 1] + dp[k + 1][j] + a[i - 1] * a[k] * a[j + 1];
        dp[i][j] = max(dp[i][j], coins);
      }
    }
  }
  return dp[1][N - 2];
}
int main()
{

  return 0;
}