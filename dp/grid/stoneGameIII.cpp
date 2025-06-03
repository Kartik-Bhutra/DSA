// https://leetcode.com/problems/stone-game-iii/description/
#include <bits/stdc++.h>
using namespace std;
string stoneGameIII(vector<int> &A)
{
  vector<int> dp(4);
  for (int i = A.size() - 1; i >= 0; --i)
  {
    dp[i % 4] = -1e9;
    for (int k = 0, take = 0; k < 3 && i + k < A.size(); ++k)
      dp[i % 4] = max(dp[i % 4], (take += A[i + k]) - dp[(i + k + 1) % 4]);
  }
  return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
}
class Solution
{
  pair<int, int> maxScore(vector<int> &nums, int i, bool k, vector<vector<pair<int, int>>> &dp)
  {
    if (i >= nums.size())
      return {0, 0};
    if (dp[i][k].first != -1e9)
      return dp[i][k];
    pair<int, int> ans = {-1e9, -1e9};
    int temp = 0;
    for (int j = 0; j < 3 && i + j < nums.size(); j++)
    {
      temp += nums[i + j];
      auto t = maxScore(nums, i + j + 1, !k, dp);
      if (k)
      {
        if (t.first + temp > ans.first)
        {
          ans = {t.first + temp, t.second};
        }
      }
      else
      {
        if (t.second + temp > ans.second)
        {
          ans = {t.first, t.second + temp};
        }
      }
    }
    return dp[i][k] = ans;
  }

public:
  string stoneGameIII(vector<int> &stoneValue)
  {
    vector<vector<pair<int, int>>> dp(stoneValue.size(), vector<pair<int, int>>(2, {-1e9, -1e9}));
    auto ans = maxScore(stoneValue, 0, 1, dp);
    if (ans.first > ans.second)
    {
      return "Alice";
    }
    else if (ans.first == ans.second)
    {
      return "Tie";
    }
    return "Bob";
  }
};

int main()
{

  return 0;
}