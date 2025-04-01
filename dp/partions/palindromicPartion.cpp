#include <bits/stdc++.h>
using namespace std;
int minCut(string s)
{
  int n = s.size();
  vector<int> dp(n, -1);
  auto isPalindrome = [&](int i, int j) -> bool
  {
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  };
  function<int(int)> minPartitions = [&](int i) -> int
  {
    if (i == n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
      if (isPalindrome(i, j))
      {
        int cost = 1 + minPartitions(j + 1);
        minCost = min(minCost, cost);
      }
    }
    return dp[i] = minCost;
  };
  return minPartitions(0) - 1;
}
int palindromePartitioning(string s)
{
  int n = s.size();
  auto isPalindrome = [&](int i, int j)
  {
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  };
  vector<int> dp(n + 1, 0);
  dp[n] = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
      if (isPalindrome(i, j))
      {
        int cost = 1 + dp[j + 1];
        minCost = min(minCost, cost);
      }
    }
    dp[i] = minCost;
  }
  return dp[0] - 1;
}
int minCut(string s)
{
  int n = s.size();
  vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
  vector<int> dp(n, 0);

  for (int i = 0; i < n; ++i)
  {
    int minCuts = i;
    for (int j = 0; j <= i; ++j)
    {
      if (s[j] == s[i] && (j + 1 > i - 1 || isPalindrome[j + 1][i - 1]))
      {
        isPalindrome[j][i] = true;
        minCuts = (j == 0) ? 0 : min(minCuts, dp[j - 1] + 1);
      }
    }
    dp[i] = minCuts;
  }

  return dp[n - 1];
}
int main()
{
  string str = "aab";
  cout << "Minimum cuts needed for palindrome partitioning: " << minCut(str) << endl;
  return 0;
}