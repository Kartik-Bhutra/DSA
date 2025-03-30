// https://leetcode.com/problems/distinct-subsequences/description/
#include <bits/stdc++.h>
using namespace std;
int numDistinct(string s, string t)
{
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  function<int(int i, int j)> r = [&](int i, int j) -> int
  {
    if (j == -1)
      return 1;
    if (i == -1)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == t[j])
    {
      return dp[i][j] = r(i - 1, j) + r(i - 1, j - 1);
    }
    return dp[i][j] = r(i - 1, j);
  };
  return r(n - 1, m - 1);
}
int numDistinct(string s, string t)
{
  int n = s.size(), m = t.size();
  vector<int> dp(m + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= 1; j--)
    {
      if (s[i - 1] == t[j - 1])
      {
        dp[j] += dp[j - 1];
      }
    }
  }
  return dp[m];
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s, t;
    cin >> s >> t;
    cout << numDistinct(s, t) << endl;
  }
  return 0;
}