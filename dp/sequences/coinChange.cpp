// https://leetcode.com/problems/coin-change/
// https://leetcode.com/problems/coin-change-ii/description/
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &a, int k)
{
  int n = a.size();
  vector<int> dp(k + 1, INT_MAX - 1);
  dp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = a[i]; j <= k; j++)
    {
      dp[j] = min(dp[j], dp[j - a[i]] + 1);
    }
  }
  return (dp[k] == INT_MAX - 1) ? -1 : dp[k];
}
int change(int k, vector<int> &a)
{
  int n = a.size();
  vector<int> dp(k + 1, 0);
  dp[0] = 1; 
  for (int i = 0; i < n; i++)
  {
    for (int j = a[i]; j <= k; j++)
    {
      dp[j] += dp[j - a[i]];
    }
  }
  return dp[k];
}
int main()
{
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  cout << "Fewest number of coins: " << coinChange(coins, amount) << endl;
  return 0;
}