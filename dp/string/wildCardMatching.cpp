// https://leetcode.com/problems/wildcard-matching/
#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p)
{
  int n = s.size(), m = p.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  function<bool(int, int)> r = [&](int i, int j) -> bool
  {
    if (j == -1)
      return i == -1;
    if (i == -1)
    {
      for (int k = 0; k <= j; k++)
        if (p[k] != '*')
          return false;
      return true;
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == p[j] || p[j] == '?')
      return dp[i][j] = r(i - 1, j - 1);
    if (p[j] == '*')
      return dp[i][j] = r(i - 1, j) || r(i, j - 1);
    return dp[i][j] = 0;
  };
  return r(n - 1, m - 1);
}
bool isMatch(string s, string p)
{
  int m = s.size(), n = p.size();
  vector<bool> dp(m + 1, false), newdp(m + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; i++)
  {
    newdp[0] = (p[i - 1] == '*' && dp[0]);
    for (int j = 1; j <= m; j++)
    {
      if (p[i - 1] == '*')
      {
        newdp[j] = dp[j] || newdp[j - 1];
      }
      else if (p[i - 1] == '?' || p[i - 1] == s[j - 1])
      {
        newdp[j] = dp[j - 1];
      }
      else
      {
        newdp[j] = false;
      }
    }
    dp = newdp;
  }
  return dp[m];
}
bool isMatch(string s, string p)
{
  int i = 0, j = 0;
  int star = -1, match = 0;
  while (i < s.size())
  {
    if (j < p.size() && (p[j] == s[i] || p[j] == '?'))
    {
      i++;
      j++;
    }
    else if (j < p.size() && p[j] == '*')
    {
      star = j;
      match = i;
      j++;
    }
    else if (star >= 0)
    {
      j = star + 1;
      i = ++match;
    }
    else
    {
      return false;
    }
  }
  while (j < p.size() && p[j] == '*')
  {
    j++;
  }
  return j == p.size();
}

int main()
{
  return 0;
}