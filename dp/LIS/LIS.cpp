// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
// https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;
vector<int> longestIncreasingSubsequence(int n, std::vector<int> &arr)
{
  vector<int> dp(n, 1), pre(n, -1);
  int ans = 1;
  int s = 0, lis = 1;
  for (int i = 1; i < n; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
      {
        dp[i] = dp[j] + 1;
        pre[i] = j;
        if (dp[i] > lis)
        {
          ans = 1;
          lis = dp[i];
          s = i;
        }
      }
      else if (lis == dp[j] + 1)
      {
        ans++;
      }
    }
  }
  std::vector<int> ret;
  do
  {
    ret.push_back(arr[s]);
    s = pre[s];
  } while (s != -1);
  reverse(ret.begin(), ret.end());
  return ret;
}
int lengthOfLIS(vector<int> &a)
{
  vector<int> dp;
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if (j == dp.size())
    {
      dp.push_back(a[i]);
    }
    else
    {
      dp[j] = a[i];
    }
  }
  return dp.size();
}
int main()
{
  return 0;
}