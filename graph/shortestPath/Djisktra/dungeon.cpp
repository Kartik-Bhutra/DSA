// https://leetcode.com/problems/dungeon-game/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int m = dungeon.size(), n = dungeon[0].size();
    int low = 1, high = 1e9, ans = 1e9;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      queue<pair<int, int>> q;
      vector<vector<int>> hp(m, vector<int>(n, -1));

      q.push({0, 0});
      hp[0][0] = mid + dungeon[0][0];
      if (hp[0][0] <= 0)
      {
        low = mid + 1;
        continue;
      }

      while (!q.empty())
      {
        auto [x, y] = q.front();
        q.pop();
        visited[x][y] = true;

        int dx[2] = {1, 0}, dy[2] = {0, 1};
        for (int d = 0; d < 2; ++d)
        {
          int nx = x + dx[d], ny = y + dy[d];
          if (nx >= m || ny >= n)
            continue;
          int new_hp = hp[x][y] + dungeon[nx][ny];
          if (new_hp <= 0)
            continue;
          if (new_hp > hp[nx][ny])
          {
            hp[nx][ny] = new_hp;
            q.push({nx, ny});
          }
        }
      }

      if (hp[m - 1][n - 1] > 0)
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}