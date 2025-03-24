// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include <bits/stdc++.h>
using namespace std;
int knapSack(vector<int> &v, vector<int> &wt, int W)
{
  int n = v.size();
  vector<int> dp(W + 1, 0);

  for (int i = wt[0]; i <= W; i++)
  {
    dp[i] = (i / wt[0]) * v[0];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      int nt = dp[j];
      int t = INT_MIN;
      if (wt[i] <= j)
        t = v[i] + dp[j - wt[i]];
      dp[j] = max(nt, t);
    }
  }
  return dp[W];
}
int main()
{
  return 0;
}