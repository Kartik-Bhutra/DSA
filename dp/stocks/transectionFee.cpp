// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &a, int f)
{
  int ans = 0;
  int buy = 1e9;
  for (int i = 0; i < a.size(); i++)
  {
    ans = max(a[i] - buy - f, ans);
    buy = min(buy, a[i] - ans);
  }
  return ans;
}
int main()
{
  return 0;
}