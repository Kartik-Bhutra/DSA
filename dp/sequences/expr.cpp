// https://leetcode.com/problems/target-sum/description/
#include <bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int> &a, int k)
{
  unordered_map<int, int> c;
  c[0] = 1;
  for (int n : a)
  {
    unordered_map<int, int> t;
    for (const auto &[s, ct] : c)
    {
      t[s + n] += ct;
      t[s - n] += ct;
    }
    c = t;
  }
  return c[k];
}
int findTargetSumWays2(vector<int> &a, int k)
{
  int s = accumulate(a.begin(), a.end(), 0);
  int d = s - k;
  if(d%2 || d < 0)  return 0;
  int n = a.size();
  d = d/2;
  vector<int> dp(d + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = d; j >= a[i]; j--)
    {
      dp[j] += dp[j - a[i]];
    }
  }
  return dp[d];
}
int main()
{
  return 0;
}