// https://leetcode.com/problems/unique-paths/description/
#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n)
{
  vector<int> dp(n, 1);
  for (int i = 1; i < m; i++)
  {
    int s = 1;
    for (int j = 1; j < n; j++)
    {
      s += dp[j];
      dp[j] = s;
    }
  }
  return dp[n - 1];
}
int main()
{
  return 0;
}