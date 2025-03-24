// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include <bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &p)
{
  int n = p.size();
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    dp[i] = (i / 1) * p[0];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      int nt = dp[j];
      int t = INT_MIN;
      if (i + 1 <= j)
        t = p[i] + dp[j - (i + 1)];
      dp[j] = max(nt, t);
    }
  }
  return dp[n];
}
int main()
{
  return 0;
}