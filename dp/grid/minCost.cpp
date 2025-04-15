#include <bits/stdc++.h>
using namespace std;
int cost(vector<vector<int>> &m)
{
  int n = m.size();
  vector<int> dp(n), newdp(n);
  vector<int> colMin(n);
  dp[0] = 0;
  int runningMin = m[0][0];
  for (int j = 0; j < n; ++j)
  {
    colMin[j] = m[0][j];
    if (j > 0)
    {
      dp[j] = dp[j - 1] + runningMin;
      runningMin = min(runningMin, m[0][j]);
    }
  }
  for (int i = 1; i < n; ++i)
  {
    newdp[0] = dp[0] + colMin[0];
    int mj = m[i][0];
    for (int j = 1; j < n; ++j)
    {
      newdp[j] = min(dp[j] + colMin[j], newdp[j - 1] + mj);
      mj = min(mj, m[i][j]);
    }
    for (int j = 0; j < n; ++j)
    {
      colMin[j] = min(colMin[j], m[i][j]);
    }
    dp.swap(newdp);
  }
  return dp[n - 1];
}
int main()
{

  return 0;
}