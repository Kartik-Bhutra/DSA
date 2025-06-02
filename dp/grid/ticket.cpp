// https://leetcode.com/problems/minimum-cost-for-tickets/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  int nextday(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
  {
    if (i == days.size())
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int ans = costs[0] + nextday(days, costs, i + 1, dp);
    ans = min(costs[1] + nextday(days, costs, lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin(), dp), ans);
    ans = min(costs[2] + nextday(days, costs, lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin(), dp), ans);
    return dp[i] = ans;
  }

public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    vector<int> dp(days.size(), -1);
    return nextday(days, costs, 0, dp);
  }
};
class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    int lastDay = days[days.size() - 1];
    vector<int> dp(lastDay + 1, 0);
    int i = 0;
    for (int day = 1; day <= lastDay; day++)
    {
      if (day < days[i])
      {
        dp[day] = dp[day - 1];
      }
      else
      {
        i++;
        dp[day] = min({dp[day - 1] + costs[0],
                       dp[max(0, day - 7)] + costs[1],
                       dp[max(0, day - 30)] + costs[2]});
      }
    }
    return dp[lastDay];
  }
};
int main()
{
  return 0;
}