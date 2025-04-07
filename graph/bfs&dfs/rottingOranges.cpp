// https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &mat)
{
  int n = mat.size();
  queue<pair<pair<int, int>, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mat[i][j] == 2)
        q.push({{i, j}, 0});
    }
  }
  int ans = 0;
  while (q.size())
  {
    auto [cell, r] = q.front();
    auto [i, j] = cell;
    ans = max(ans, r);
    q.pop();
    if (i > 0 && mat[i - 1][j] == 1)
    {
      mat[i - 1][j] = 2;
      q.push({{i - 1, j}, r + 1});
    }
    if (j > 0 && mat[i][j - 1] == 1)
    {
      mat[i][j - 1] = 2;
      q.push({{i, j - 1}, r + 1});
    }
    if (i < n - 1 && mat[i + 1][j] == 1)
    {
      mat[i + 1][j] = 2;
      q.push({{i + 1, j}, r + 1});
    }
    if (j < n - 1 && mat[i][j + 1] == 1)
    {
      mat[i][j + 1] = 2;
      q.push({{i, j + 1}, r + 1});
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mat[i][j] == 1)
        return -1;
    }
  }
  return ans;
}
int main()
{

  return 0;
}