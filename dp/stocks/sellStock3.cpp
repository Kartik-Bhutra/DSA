// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &a)
{
  int b1 = INT_MAX, b2 = INT_MAX;
  int s1 = 0, s2 = 0;
  for (int i : a)
  {
    b1 = min(b1, i);
    s1 = max(s1, i - b1);
    b2 = min(b2, i - s1);
    s2 = max(s2, i - b2);
  }
  return s2;
}
int maxProfit(vector<int> &a)
{
  int n = a.size();
  int left[n], right[n];
  int leftmin = a[0], rightmax = a[n - 1], maxprofit = 0;
  left[0] = 0;
  right[n - 1] = 0;
  int i, j;
  for (i = 1, j = n - 2; i < n, j >= 0; i++, j--)
  {
    leftmin = min(leftmin, a[i]);
    left[i] = max(left[i - 1], a[i] - leftmin);
    rightmax = max(rightmax, a[j]);
    right[j] = max(right[j + 1], rightmax - a[j]);
  }
  for (int i = 0; i < n; i++)
  {
    maxprofit = max(maxprofit, left[i] + right[i]);
  }
  return maxprofit;
}
int maxProfit(vector<int> &a)
{
  int n = a.size();
  vector<int> before(5, 0);
  vector<int> after(5, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    for (int t = 3; t >= 0; t--)
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