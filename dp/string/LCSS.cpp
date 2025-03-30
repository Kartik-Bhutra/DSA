// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
#include <bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string &s1, string &s2)
{
  int n1 = s1.size(), n2 = s2.size();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  int ans = 0;
  for (int i = 1; i <= n1; i++)
  {
    for (int j = 1; j <= n2; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  }
  return ans;
}
int longestCommonSubstr(string &s1, string &s2)
{
  int n1 = s1.size(), n2 = s2.size();
  vector<int> dp(n2 + 1, 0);
  int ans = 0;
  for (int i = 1; i <= n1; i++)
  {
    vector<int> dp2(n2 + 1, 0);
    for (int j = 1; j <= n2; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp2[j] = dp[j - 1] + 1;
        ans = max(ans, dp2[j]);
      }
    }
    dp = dp2;
  }
  return ans;
}
int main()
{

  return 0;
}