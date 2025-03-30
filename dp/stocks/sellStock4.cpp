// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int k, vector<int> &a)
{
  int n = a.size();
  vector<int> before(2 * k + 1, 0);
  vector<int> after(2 * k + 1, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    for (int t = 2 * k - 1; t >= 0; t--)
    {
      if (t % 2 == 0)
        after[t] = max(-a[i] + before[t + 1], before[t]);
      else
        after[t] = max(a[i] + before[t + 1], before[t]);
    }
    before = after;
  }
  return after[0];
}
int main()
{

  return 0;
}