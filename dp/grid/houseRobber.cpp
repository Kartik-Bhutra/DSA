// https://leetcode.com/problems/house-robber-ii/description/
#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
  vector<int> dp(2, 0);
  dp[1] = nums[0];
  for (int i = 1; i < nums.size() - 1; i++)
  {
    int x = max(dp[1], dp[0] + nums[i]);
    dp[0] = dp[1];
    dp[1] = x;
  }
  int x = dp[1];
  dp[1] = 0;
  dp[0] = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    int x = max(dp[1], dp[0] + nums[i]);
    dp[0] = dp[1];
    dp[1] = x;
  }
  return max(x, dp[1]);
}
int main()
{
  return 0;
}