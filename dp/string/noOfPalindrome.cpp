// https://www.naukri.com/code360/problems/count-palindromic-subsequences_1062696?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int ctt(int i, int j, string &s, vector<vector<int>> &dp)
{
  if (i > j)
  {
    return 0;
  }
  if (i == j)
  {
    return 1;
  }
  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }
  if (s[i] == s[j])
  {
    return dp[i][j] = (1 + ctt(i + 1, j, s, dp) + ctt(i, j - 1, s, dp)) % mod;
  }
  else
  {
    return dp[i][j] = ((ctt(i + 1, j, s, dp) + ctt(i, j - 1, s, dp)) % mod - ctt(i + 1, j - 1, s, dp) + mod) % mod;
  }
}
int countPalindromicSubsequences(string &s)
{
  vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
  return ctt(0, s.size() - 1, s, dp);
}
int countPalindromicSubsequences(string &s)
{
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i; j < n; j++)
    {
      int len = j - i + 1;
      if (len == 1)
      {
        dp[i][j] = 1;
      }
      else if (len == 2)
      {
        if (s[i] == s[j])
        {
          dp[i][j] = 3;
        }
        else
        {
          dp[i][j] = 2;
        }
      }
      else
      {
        if (s[i] == s[j])
        {
          dp[i][j] = (1 + dp[i + 1][j] + dp[i][j - 1]) % mod;
        }
        else
        {
          dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1] + mod) % mod;
        }
      }
    }
  }
  return dp[0][n - 1];
}
int countPalindromicSubsequences(string &s)
{
  int n = s.size();
  vector<int> curr(n), prev(n);
  for (int i = n - 1; i >= 0; i--)
  {
    curr[i] = 1;
    int diag = 0;
    for (int j = i + 1; j < n; j++)
    {
      int temp = curr[j];
      if (s[i] == s[j])
      {
        curr[j] = (1 + prev[j] + curr[j - 1]) % mod;
      }
      else
      {
        curr[j] = ((prev[j] + curr[j - 1]) % mod - diag + mod) % mod;
      }
      diag = temp;
    }
    prev = curr;
  }
  return curr[n - 1];
}
int main()
{
  return 0;
}