// https://leetcode.com/problems/trapping-rain-water-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  vector<int> rainWater(vector<int> &heights)
  {
    int n = heights.size();
    vector<int> ans(n, 0);
    int leftMax = heights[0], rightMax = heights[n - 1];
    int i = 1, j = n - 2;
    while (i <= j)
    {
      if (leftMax < rightMax)
      {
        leftMax = max(leftMax, heights[i]);
        ans[i] = max(0, leftMax - heights[i]);
        i++;
      }
      else
      {
        rightMax = max(rightMax, heights[j]);
        ans[j] = max(0, rightMax - heights[j]);
        j--;
      }
    }
    return ans;
  }

public:
  int trapRainWater(vector<vector<int>> &heightMap)
  {
    int m = heightMap.size(), n = heightMap[0].size();

    vector<vector<int>> rowTrap(m);
    for (int i = 0; i < m; i++)
    {
      rowTrap[i] = rainWater(heightMap[i]);
    }
    vector<vector<int>> colTrap(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
      vector<int> col(m);
      for (int i = 0; i < m; i++)
        col[i] = heightMap[i][j];

      vector<int> trapped = rainWater(col);
      for (int i = 0; i < m; i++)
        colTrap[i][j] = trapped[i];
    }
    vector<vector<int>> draft1Trap(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        draft1Trap[i][j] = min(colTrap[i][j], rowTrap[i][j]);
      }
    }
    cout << "draft1Trap:" << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << draft1Trap[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (draft1Trap[i][j] && !vis[i][j])
        {
          vector<int> comp;
          int mini = INT_MAX;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty())
          {
            auto [r, c] = q.front();
            q.pop();
            if (vis[r][c])
              continue;
            comp.push_back(heightMap[r][c]);
            mini = min(mini, heightMap[r][c] + draft1Trap[r][c]);
            for (auto [dr, dc] : dirs)
            {
              int nr = r + dr, nc = c + dc;
              if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc])
                mini = min(mini, heightMap[nr][nc] + draft1Trap[nr][nc]);
            }
            vis[r][c] = true;
            for (auto [dr, dc] : dirs)
            {
              int nr = r + dr, nc = c + dc;
              if (nr >= 0 && nr < m && nc >= 0 && nc < n && draft1Trap[nr][nc])
              {
                q.push({nr, nc});
              }
            }
          }
          for (int k : comp)
          {
            if (k <= mini)
            {
              ans += mini - k;
            }
          }
          // cout << mini << " " << comp.size() << " " << accumulate(comp.begin(), comp.end(), 0) << endl;
        }
      }
    }
    return ans;
  }
};

int main()
{
  vector<vector<int>> heightMap = {
      {14, 20, 11, 19, 19, 16},
      {11, 10, 7, 4, 9, 6},
      {17, 2, 2, 6, 10, 9},
      {15, 9, 2, 1, 4, 1},
      {15, 5, 5, 5, 8, 7},
      {14, 2, 8, 6, 10, 7}};

  Solution s;
  cout << s.trapRainWater(heightMap) << endl;

  return 0;
}

// work in progress
