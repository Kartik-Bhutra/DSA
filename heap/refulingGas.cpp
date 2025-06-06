// https://leetcode.com/problems/minimum-number-of-refueling-stops/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minRefuelStops(int target, int tank, vector<vector<int>> &stations)
  {
    priority_queue<int> pq;
    int ans = 0, prev = 0;

    for (const auto &station : stations)
    {
      int location = station[0];
      int capacity = station[1];
      tank -= location - prev;

      while (!pq.empty() && tank < 0)
      {
        tank += pq.top();
        pq.pop();
        ans++;
      }

      if (tank < 0)
        return -1;
      pq.push(capacity);
      prev = location;
    }

    tank -= target - prev;
    while (!pq.empty() && tank < 0)
    {
      tank += pq.top();
      pq.pop();
      ans++;
    }
    if (tank < 0)
      return -1;

    return ans;
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