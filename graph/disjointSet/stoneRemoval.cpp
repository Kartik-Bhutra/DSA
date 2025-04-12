// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;
int removeStones(vector<vector<int>> &stones)
{
  int maxRow = 0;
  int maxCol = 0;
  for (auto it : stones)
  {
    maxRow = max(maxRow, it[0]);
    maxCol = max(maxCol, it[1]);
  }
  ds deca(maxRow + maxCol + 1);
  unordered_map<int, int> stoneNodes;
  for (auto it : stones)
  {
    int nodeRow = it[0];
    int nodeCol = it[1] + maxRow + 1;
    deca.unionByRank(nodeRow, nodeCol);
    stoneNodes[nodeRow] = 1;
    stoneNodes[nodeCol] = 1;
  }

  int cnt = 0;
  for (auto it : stoneNodes)
  {
    if (deca.findParent(it.first) == it.first)
    {
      cnt++;
    }
  }
  return stones.size() - cnt;
}
void dfs(vector<vector<int>> &stones, int idx, vector<bool> &visited)
{
  visited[idx] = true;
  for (int i = 0; i < stones.size(); i++)
  {
    int r = stones[idx][0];
    int c = stones[idx][1];
    if (!visited[i] and (stones[i][0] == r || stones[i][1] == c))
    {
      dfs(stones, i, visited);
    }
  }
}

int removeStones(vector<vector<int>> &stones)
{
  int n = stones.size();
  vector<bool> visited(n, false);

  int groups = 0;
  for (int i = 0; i < n; i++)
  {
    if (visited[i] == true)
      continue;
    dfs(stones, i, visited);
    groups++;
  }
  return n - groups;
}
int main()
{

  return 0;
}