// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/1477385576/
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>> &r)
{
  vector<vector<pair<int, int>>> adj(n);
  for (const auto &edge : r)
  {
    adj[edge[0]].emplace_back(edge[1], edge[2]);
    adj[edge[1]].emplace_back(edge[0], edge[2]);
  }
  vector<long long> dist(n, LLONG_MAX);
  vector<int> ways(n, 0);
  dist[0] = 0;
  ways[0] = 1;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
  pq.emplace(0, 0);
  while (!pq.empty())
  {
    auto [d, node] = pq.top();
    pq.pop();
    if (d > dist[node])
      continue;
    for (const auto &[next, weight] : adj[node])
    {
      if (dist[next] > d + weight)
      {
        dist[next] = d + weight;
        ways[next] = ways[node];
        pq.emplace(dist[next], next);
      }
      else if (dist[next] == d + weight)
      {
        ways[next] = (ways[next] + ways[node]) % mod;
      }
    }
  }
  return ways[n - 1];
}
int main()
{
  return 0;
}