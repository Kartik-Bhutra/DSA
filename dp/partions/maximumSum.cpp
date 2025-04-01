// https://leetcode.com/problems/partition-array-for-maximum-sum/
#include <bits/stdc++.h>
using namespace std;
int maxSumAfterPartitioning(vector<int> &a, int k)
{
  int n = a.size();
  vector<int> dp(n, -1);
  function<int(int)> r = [&](int i) -> int
  {
    if (i == n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int ct = 0, maxi = 0, ans = 0;
    for (int j = i; j < min(n, i + k); j++)
    {
      maxi = max(maxi, a[j]);
      ans = max(ans, maxi * (j - i + 1) + r(j + 1));
    }
    return dp[i] = ans;
  };
  return r(0);
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> dp(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    int len = 0, maxi = INT_MIN, maxSum = 0;
    for (int j = i; j < min(n, i + k); j++)
    {
      len++;
      maxi = max(maxi, arr[j]);
      int sum = maxi * len + dp[j + 1];
      maxSum = max(maxSum, sum);
    }
    dp[i] = maxSum;
  }
  return dp[0];
}
int main()
{
  return 0;
}