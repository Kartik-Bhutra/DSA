// https://leetcode.com/problems/minimum-number-of-refueling-stops/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
  {
    int N = stations.size();
    vector<long long> dp(N + 1, 0);
    dp[0] = startFuel;

    for (int i = 0; i < N; ++i)
    {
      for (int t = i; t >= 0; --t)
      {
        if (dp[t] >= stations[i][0])
        {
          dp[t + 1] = max(dp[t + 1], dp[t] + (long long)stations[i][1]);
        }
      }
    }

    for (int i = 0; i <= N; ++i)
    {
      if (dp[i] >= target)
      {
        return i;
      }
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  int target = 100;
  int startFuel = 10;

  cout << "Minimum refueling stops needed: "
       << sol.minRefuelStops(target, startFuel, stations) << endl;
  return 0;
}