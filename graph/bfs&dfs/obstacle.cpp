// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int shortestPath(vector<vector<int>> &grid, int k)
  {
    int m = grid.size();
    int n = grid[0].size();

    if (m == 1 && n == 1)
    {
      return 0;
    }

    if (k >= m + n - 2)
    {
      return m + n - 2;
    }

    vector<vector<vector<bool>>> visited(
        m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, k);
    visited[0][0][k] = true;

    int steps = 0;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
    {
      int sz = q.size();
      while (sz--)
      {
        auto [x, y, rem] = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1)
        {
          return steps;
        }

        for (auto &d : dirs)
        {
          int nx = x + d[0], ny = y + d[1];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          {
            continue;
          }

          int nk = rem - grid[nx][ny];

          if (nk < 0)
          {
            continue;
          }

          if (!visited[nx][ny][nk])
          {
            visited[nx][ny][nk] = true;
            q.emplace(nx, ny, nk);
          }
        }
      }

      ++steps;
    }

    return -1;
  }
};
int main()
{

  return 0;
}