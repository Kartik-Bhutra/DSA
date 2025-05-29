// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dfs(vector<vector<int>> &mat, int r, int c, int pre, vector<vector<int>> &dp)
  {
    if (r == -1 || r == mat.size() || c == -1 || c == mat[0].size())
      return 0;
    if (pre >= mat[r][c])
      return 0;
    if (dp[r][c] != -1)
      return dp[r][c];
    return dp[r][c] = 1 + max({dfs(mat, r, c + 1, mat[r][c], dp), dfs(mat, r, c - 1, mat[r][c], dp), dfs(mat, r + 1, c, mat[r][c], dp), dfs(mat, r - 1, c, mat[r][c], dp)});
  }
  int longestIncreasingPath(vector<vector<int>> &mat)
  {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        ans = max(ans, dfs(mat, i, j, -1, dp));
      }
    }
    return ans;
  }
};
class Solution
{
public:
  vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int m, n;

  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    m = matrix.size();
    n = matrix[0].size();

    vector<vector<int>> indeg(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        for (auto dir : direction)
        {
          int nr = i + dir.first;
          int nc = j + dir.second;

          if (nr >= 0 && nc >= 0 && nr < m && nc < n && matrix[nr][nc] > matrix[i][j])
          {
            indeg[nr][nc]++;
          }
        }
      }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (indeg[i][j] == 0)
        {
          q.push(make_pair(i, j));
        }
      }
    }

    int level = 0;
    while (!q.empty())
    {
      level++;
      int t = q.size();
      for (int i = 0; i < t; i++)
      {

        auto node = q.front();
        q.pop();
        for (auto dir : direction)
        {

          int nr = node.first + dir.first;
          int nc = node.second + dir.second;

          if (nr >= 0 && nc >= 0 && nr < m && nc < n && matrix[nr][nc] > matrix[node.first][node.second])
          {
            indeg[nr][nc]--;
            if (indeg[nr][nc] == 0)
            {
              q.push(make_pair(nr, nc));
            }
          }
        }
      }
    }

    return level;
  }
};
int main()
{

  return 0;
}