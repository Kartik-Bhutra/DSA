// https://leetcode.com/problems/delete-operation-for-two-strings/description/
#include <bits/stdc++.h>
using namespace std;
int minDistance(string s1, string s2)
{
  int l1 = s1.length(), l2 = s2.length();
  if (l1 < l2)
    return minDistance(s2, s1);
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
  return l2 + l1 - 2 * dp[l2];
}
int main()
{

  return 0;
}