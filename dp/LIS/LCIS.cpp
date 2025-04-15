// https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/
#include <bits/stdc++.h>
using namespace std;
int LCIS(vector<int> &a, vector<int> &b)
{
  int m = a.size();
  int n = b.size();
  vector<int> dp(n, 0);
  for (int i = 0; i < m; i++)
  {
    int currentLength = 0;
    for (int j = 0; j < n; j++)
    {
      if (a[i] == b[j])
      {
        dp[j] = max(dp[j], currentLength + 1);
      }
      else if (a[i] > b[j])
      {
        currentLength = max(currentLength, dp[j]);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}
int findLCIS(int i, int j, int prevIndex, vector<int> &a,
             vector<int> &b, vector<vector<vector<int>>> &memo)
{
  if (i < 0 || j < 0)
    return 0;
  if (memo[i][j][prevIndex + 1] != -1)
    return memo[i][j][prevIndex + 1];
  int include = 0;
  int exclude = 0;
  if (a[i] == b[j] &&
      (prevIndex == -1 || a[i] < a[prevIndex]))
  {
    include = 1 + findLCIS(i - 1, j - 1, i, a, b, memo);
  }
  exclude =
      max(findLCIS(i - 1, j, prevIndex, a, b, memo),
          findLCIS(i, j - 1, prevIndex, a, b, memo));
  memo[i][j][prevIndex + 1] = max(include, exclude);
  return memo[i][j][prevIndex + 1];
}
int LCIS(vector<int> &a, vector<int> &b)
{
  int m = a.size();
  int n = b.size();
  vector<vector<vector<int>>> memo(m,
                                   vector<vector<int>>(n, vector<int>(m + 1, -1)));
  return findLCIS(m - 1, n - 1, -1, a, b, memo);
}
int main()
{
  return 0;
}