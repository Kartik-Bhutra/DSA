#include <bits/stdc++.h>
using namespace std;
bool spfaDetectNegativeCycle(int n, vector<vector<pair<int, int>>> &adj)
{
  vector<int> count(n, 0);
  vector<int> dist(n, 1e9);
  vector<bool> inQueue(n, false);
  queue<int> q;
  dist[0] = 0;
  q.push(0);
  inQueue[0] = true;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    inQueue[u] = false;
    for (auto [v, w] : adj[u])
    {
      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        if (!inQueue[v])
        {
          q.push(v);
          inQueue[v] = true;
          count[v]++;
          if (count[v] > n)
            return true; 
        }
      }
    }
  }
  return false;
}
int main()
{
  return 0;
}