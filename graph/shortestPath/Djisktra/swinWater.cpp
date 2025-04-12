// https://leetcode.com/problems/swim-in-rising-water/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({grid[0][0], {0, 0}});
    visited[0][0] = 1;

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxTime = 0;

    while (!pq.empty())
    {
      auto current = pq.top();
      pq.pop();

      int time = current.first;
      int x = current.second.first;
      int y = current.second.second;

      maxTime = max(maxTime, time);

      if (x == n - 1 && y == n - 1)
        return maxTime;

      for (auto &dir : directions)
      {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
            !visited[nx][ny])
        {
          visited[nx][ny] = 1;
          pq.push({grid[nx][ny], {nx, ny}});
        }
      }
    }

    return -1;
  }
};

int main()
{

  return 0;
}