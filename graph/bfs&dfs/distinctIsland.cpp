// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std;
int countDistinctIslands(vector<vector<int>> &g)
{
  int n = g.size(), m = g[0].size();
  unordered_set<string> st;
  int ans = 0;
  auto bfs = [&](int i, int j)
  {
    queue<pair<int, int>> q;
    q.push({i, j});
    string s = "";
    while (!q.empty())
    {
      auto [r, c] = q.front();
      g[r][c] = 0;
      if (r && g[r - 1][c])
      {
        s += "t";
        q.push({r - 1, c});
      }
      if (c && g[r][c - 1])
      {
        s += "l";
        q.push({r, c - 1});
      }
      if (r < n - 1 && g[r + 1][c])
      {
        s += "b";
        q.push({r + 1, c});
      }
      if (c < m - 1 && g[r][c + 1])
      {
        s += "r";
        q.push({r, c + 1});
      }
      s += "-";
    }
    if (st.find(s) == st.end())
    {
      ans++;
      st.insert(s);
    }
  };
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (g[i][j])
      {
        bfs(i, j);
      }
    }
  }
  return ans;
}
int main()
{

  return 0;
}