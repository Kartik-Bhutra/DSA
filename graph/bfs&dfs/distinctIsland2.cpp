// https://leetcode.com/problems/number-of-distinct-islands-ii/description/
#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> Point;
class Solution
{
public:
  int numDistinctIslands2(vector<vector<int>> &grid)
  {
    set<vector<Point>> uniqueShapes;
    for (int row = 0; row < grid.size(); ++row)
    {
      for (int col = 0; col < grid[0].size(); ++col)
      {
        if (grid[row][col])
        {
          vector<Point> shape;
          depthFirstSearch(row, col, grid, shape);
          uniqueShapes.insert(normalizeShape(shape));
        }
      }
    }
    return uniqueShapes.size();
  }
  vector<Point> normalizeShape(vector<Point> &shape)
  {
    vector<vector<Point>> shapes(8);
    for (auto &point : shape)
    {
      int x = point.first, y = point.second;
      shapes[0].push_back({x, y});
      shapes[1].push_back({x, -y});
      shapes[2].push_back({-x, y});
      shapes[3].push_back({-x, -y});
      shapes[4].push_back({y, x});
      shapes[5].push_back({y, -x});
      shapes[6].push_back({-y, -x});
      shapes[7].push_back({-y, x});
    }
    for (auto &e : shapes)
    {
      sort(e.begin(), e.end());
      int baseX = e[0].first, baseY = e[0].second;
      for (auto &point : e)
      {
        point.first -= baseX;
        point.second -= baseY;
      }
    }
    sort(shapes.begin(), shapes.end());
    return shapes[0];
  }
  void depthFirstSearch(int x, int y, vector<vector<int>> &grid, vector<Point> &shape)
  {
    static const vector<int> directions = {-1, 0, 1, 0, -1};
    shape.push_back({x, y});
    grid[x][y] = 0;
    for (int k = 0; k < 4; ++k)
    {
      int nextX = x + directions[k], nextY = y + directions[k + 1];
      if (nextX >= 0 && nextX < grid.size() && nextY >= 0 && nextY < grid[0].size() && grid[nextX][nextY] == 1)
      {
        depthFirstSearch(nextX, nextY, grid, shape);
      }
    }
  }
};
int main()
{
  return 0;
}