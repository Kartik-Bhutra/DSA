// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &a)
{
  int n = a.size();
  vector<vector<int>> dp(n, vector<int>(2, -1));
  function<int(int i, bool v)> r = [&](int i, bool v) -> int
  {
    if (i >= n)
      return 0;
    if (dp[i][v] != -1)
      return dp[i][v];
    if (v)
      return dp[i][v] = max(r(i + 1, 0) - a[i], r(i + 1, 1));
    else
      return dp[i][v] = max(r(i + 2, 1) + a[i], r(i + 1, 0));
  };
  return r(0, 1);
}
int maxProfit(vector<int> &a)
{
  int n = a.size();
  vector<int> cur(2, 0);
  vector<int> front1(2, 0);
  vector<int> front2(2, 0);
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int buy = 0; buy <= 1; buy++)
    {
      int profit;
      if (buy == 0)
      {
        profit = max(0 + front1[0], -a[ind] + front1[1]);
      }
      if (buy == 1)
      {
        profit = max(0 + front1[1], a[ind] + front2[0]);
      }
      cur[buy] = profit;
    }
    front2 = front1;
    front1 = cur;
  }
  return cur[0];
}
int main()
{
  return 0;
}