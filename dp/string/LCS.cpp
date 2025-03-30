// https://leetcode.com/problems/longest-common-subsequence/
// https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequenceR(string s1, string s2)
{
  int l1 = s1.length(), l2 = s2.length();
  vector<vector<int>> dp(l1, vector<int>(l2, -1));
  function<int(int i, int j)> r = [&](int i, int j) -> int
  {
    if (i == -1)
      return 0;
    if (j == -1)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s1[i] == s2[j])
      return 1 + r(i - 1, j - 1);
    return dp[i][j] = max(r(i - 1, j), r(i, j - 1));
  };
  return r(l1 - 1, l2 - 1);
}
int longestCommonSubsequenceI(string s1, string s2)
{
  int l1 = s1.length(), l2 = s2.length();
  vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
  for (int i = 0; i <= l1; i++)
    dp[i][0] = 0;
  for (int i = 0; i <= l2; i++)
    dp[0][i] = 0;
  for (int i = 1; i <= l1; i++)
  {
    for (int j = 1; j <= l2; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[l1][l2];
}
int longestCommonSubsequence(string s1, string s2)
{
  int l1 = s1.length(), l2 = s2.length();
  if (l1 < l2)
    return longestCommonSubsequence(s2, s1);
  vector<int> dp(l2 + 1, 0);
  for (int i = 1; i <= l1; i++)
  {
    vector<int> dp2(l1 + 1, 0);
    for (int j = 1; j <= l2; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp2[j] = 1 + dp[j - 1];
      else
        dp2[j] = max(dp[j], dp2[j - 1]);
    }
    dp = dp2;
  }
  return dp[l2];
}
vector<string> all_longest_common_subsequences(string s1, string s2)
{
  int l1 = s1.size(), l2 = s2.size();
  vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
  for (int i = 1; i <= l1; i++)
  {
    for (int j = 1; j <= l2; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  unordered_map<string, vector<string>> memo;
  function<vector<string>(int, int)> r = [&](int i, int j) -> vector<string>
  {
    if (i == 0 || j == 0)
      return {""};
    string key = to_string(i) + "," + to_string(j);
    if (memo.find(key) != memo.end())
      return memo[key];
    vector<string> result;
    if (s1[i - 1] == s2[j - 1])
    {
      vector<string> temp = r(i - 1, j - 1);
      for (string &str : temp)
        result.push_back(str + s1[i - 1]);
    }
    else
    {
      if (dp[i - 1][j] == dp[i][j])
      {
        vector<string> temp = r(i - 1, j);
        result.insert(result.end(), temp.begin(), temp.end());
      }
      if (dp[i][j - 1] == dp[i][j])
      {
        vector<string> temp = r(i, j - 1);
        result.insert(result.end(), temp.begin(), temp.end());
      }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return memo[key] = result;
  };
  return r(l1, l2);
}
vector<string> all_longest_common_subsequences(string s, string t)
{
  int l1 = s.size(), l2 = t.size();
  vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
  vector<string> res;
  function<int(int, int)> lcs = [&](int pos1, int pos2) -> int
  {
    if (pos1 == l1 || pos2 == l2)
      return 0;
    if (dp[pos1][pos2] != -1)
      return dp[pos1][pos2];
    if (s[pos1] == t[pos2])
      return dp[pos1][pos2] = 1 + lcs(pos1 + 1, pos2 + 1);
    return dp[pos1][pos2] = max(lcs(pos1 + 1, pos2), lcs(pos1, pos2 + 1));
  };
  int lcs_len = lcs(0, 0);
  function<void(string, int, int, int)> helper = [&](string cur, int pos1, int pos2, int cur_lcs)
  {
    if (cur_lcs == lcs_len)
    {
      res.push_back(cur);
      return;
    }
    if (pos1 == l1 || pos2 == l2)
      return;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      bool found = false;
      for (int i = pos1; i < l1; i++)
      {
        if (s[i] == ch)
        {
          for (int j = pos2; j < l2; j++)
          {
            if (t[j] == ch && lcs(i, j) == lcs_len - cur_lcs)
            {
              helper(cur + ch, i + 1, j + 1, cur_lcs + 1);
              found = true;
              break;
            }
          }
        }
        if (found)
          break;
      }
    }
  };
  helper("", 0, 0, 0);
  return res;
}
int main()
{
  return 0;
}