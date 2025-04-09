// https://leetcode.com/problems/path-with-minimum-effort/description/
#include <bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>> &mat)
{
  if (mat.empty())
  {
    return 0;
  }
  int n = mat.size();
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  pq.push({0, 0, 0});
  int ans = 0;
  unordered_set<string> vis;
  while (!pq.empty())
  {
    auto curr = pq.top();
    pq.pop();
    int effort = curr[0];
    int curRow = curr[1];
    int curCol = curr[2];
    ans = max(ans, effort);
    if (curRow == n - 1 && curCol == n - 1)
    {
      return ans;
    }
    vis.insert(to_string(curRow) + "," + to_string(curCol));
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (const auto &direction : directions)
    {
      int newRow = curRow + direction[0];
      int newCol = curCol + direction[1];
      if (0 <= newRow && newRow < n && 0 <= newCol && newCol < n &&
          vis.find(to_string(newRow) + "," + to_string(newCol)) == vis.end())
      {
        int newEffort = abs(mat[newRow][newCol] - mat[curRow][curCol]);
        pq.push({newEffort, newRow, newCol});
      }
    }
  }
  return ans;
}
int minimumEffortPath(vector<vector<int>> &mat)
{
  if (mat.empty())
  {
    return 0;
  }
  int n = mat.size();
  int n = mat[0].size();
  auto comp = [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
  {
    return a.second > b.second;
  };
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(comp)> pq(comp);
  pq.push({{0, 0}, 0});
  vector<vector<int>> efforts(n, vector<int>(n, INT_MAX));
  efforts[0][0] = 0;
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  while (!pq.empty())
  {
    auto curr = pq.top();
    pq.pop();
    auto [curPos, curEffort] = curr;
    auto [curRow, curCol] = curPos;
    if (curRow == n - 1 && curCol == n - 1)
    {
      return curEffort;
    }
    for (const auto &direction : directions)
    {
      int newRow = curRow + direction[0];
      int newCol = curCol + direction[1];
      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
      {
        int newEffort = max(curEffort, abs(mat[newRow][newCol] - mat[curRow][curCol]));
        if (newEffort < efforts[newRow][newCol])
        {
          efforts[newRow][newCol] = newEffort;
          pq.push({{newRow, newCol}, newEffort});
        }
      }
    }
  }
  return 0;
}
int main()
{
  return 0;
}