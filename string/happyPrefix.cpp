// https://leetcode.com/problems/longest-happy-prefix/description/
#include <bits/stdc++.h>
using namespace std;
string longestPrefix(string s)
{
  int n = s.size();
  vector<int> dp(n, 0);
  for (int i = 1; i < n; i++)
  {
    if (s[dp[i - 1]] == s[i])
    {
      dp[i] = dp[i - 1] + 1;
    }
    else
    {
      int k = dp[i - 1];
      while (k > 0 && s[k] != s[i])
        k = dp[k - 1];
      if (s[i] == s[k])
      {
        dp[i] = k + 1;
      }
    }
  }
  return s.substr(0, dp[n - 1]);
}
int main()
{

  return 0;
}