// https://leetcode.com/problems/critical-connections-in-a-network/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int timer = 1;
  void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited, vector<int> &timeOfInsertion, vector<int> &lowestTime, vector<vector<int>> &ans)
  {
    visited[node] = 1;
    timeOfInsertion[node] = lowestTime[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
      if (it == parent)
        continue;
      if (visited[it] == 0)
      {
        dfs(it, node, adj, visited, timeOfInsertion, lowestTime, ans);
        lowestTime[node] = min(lowestTime[node], lowestTime[it]);
        if (timeOfInsertion[node] < lowestTime[it])
        {
          ans.push_back({it, node});
        }
      }
      else
      {
        lowestTime[node] = min(lowestTime[node], lowestTime[it]);
      }
    }
  }
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {
    vector<vector<int>> adj(n);
    for (auto i : connections)
    {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }
    vector<int> visited(n, 0);
    vector<int> timeOfInsertion(n, 0);
    vector<int> lowestTime(n, 0);
    vector<vector<int>> ans;
    dfs(0, -1, adj, visited, timeOfInsertion, lowestTime, ans);

    return ans;
  }
};
int main()
{

  return 0;
}