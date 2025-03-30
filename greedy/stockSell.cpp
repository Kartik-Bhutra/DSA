// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &a)
{
  int n = a.size();
  int mp = 0;
  for (int i = 1; i < n; i++)
  {
    if (a[i] > a[i - 1])
    {
      mp += a[i] - a[i - 1];
    }
  }
  return mp;
}
int main()
{

  return 0;
}