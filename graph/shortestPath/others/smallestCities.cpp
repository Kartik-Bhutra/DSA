// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include <bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  for (auto it : edges)
  {
    dist[it[0]][it[1]] = it[2];
    dist[it[1]][it[0]] = it[2];
  }
  for (int i = 0; i < n; i++)
    dist[i][i] = 0;
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
          continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int cntCity = n;
  int cityNo = -1;
  for (int city = 0; city < n; city++)
  {
    int cnt = 0;
    for (int adjCity = 0; adjCity < n; adjCity++)
    {
      if (dist[city][adjCity] <= distanceThreshold)
        cnt++;
    }

    if (cnt <= cntCity)
    {
      cntCity = cnt;
      cityNo = city;
    }
  }
  return cityNo;
}
int helper(int n, int node, int thrushold, vector<vector<int>> adj[])
{
  vector<int> dist(n, INT_MAX);
  dist[node] = 0;
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
  q.push({0, node});
  while (!q.empty())
  {
    int curr = q.top()[1];
    int dis = q.top()[0];
    q.pop();
    for (auto it : adj[curr])
    {
      if (dist[it[0]] > dis + it[1])
      {
        dist[it[0]] = dis + it[1];
        q.push({dis + it[1], it[0]});
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == node)
      continue;
    if (dist[i] <= thrushold)
      res++;
  }
  return res;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
  vector<vector<int>> adj[n];
  for (auto it : edges)
  {
    adj[it[0]].push_back({it[1], it[2]});
    adj[it[1]].push_back({it[0], it[2]});
  }
  vector<int> city(n, 0);
  for (int i = 0; i < n; i++)
  {
    city[i] = helper(n, i, distanceThreshold, adj);
  }
  int mini = INT_MAX;
  int ans = -1;
  for (int i = 0; i < city.size(); i++)
  {
    if (mini >= city[i])
    {
      mini = city[i];
      ans = i;
    }
  }
  return ans;
}
int main()
{

  return 0;
}