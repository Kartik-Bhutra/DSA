
#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;
class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    int N = grid.size();
    vector<pair<int, pair<int, int>>> edges;
    ds d(N * N);

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {

        if (i + 1 < N)
        {
          edges.push_back({max(grid[i][j], grid[i + 1][j]), {i * N + j, (i + 1) * N + j}});
        }

        if (j + 1 < N)
        {
          edges.push_back({max(grid[i][j], grid[i][j + 1]), {i * N + j, i * N + j + 1}});
        }
      }
    }

    sort(edges.begin(), edges.end());

    for (auto &edge : edges)
    {
      int t = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;

      d.unionByRank(u, v);

      if (d.findParent(0) == d.findParent(N * N - 1))
      {
        return t;
      }
    }

    return 0;
  }
};
class Solution
{
public:
  vector<int> p;

  int swimInWater(vector<vector<int>> &grid)
  {
    int n = grid.size();
    p.resize(n * n);
    for (int i = 0; i < p.size(); ++i)
      p[i] = i;
    vector<int> hi(n * n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        hi[grid[i][j]] = i * n + j;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    for (int t = 0; t < n * n; ++t)
    {
      int i = hi[t] / n, j = hi[t] % n;
      for (int k = 0; k < 4; ++k)
      {
        int x = i + dirs[k], y = j + dirs[k + 1];
        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t)
          p[find(x * n + y)] = find(hi[t]);
        if (find(0) == find(n * n - 1))
          return t;
      }
    }
    return -1;
  }

  int find(int x)
  {
    if (p[x] != x)
      p[x] = find(p[x]);
    return p[x];
  }
};
int main()
{

  return 0;
}