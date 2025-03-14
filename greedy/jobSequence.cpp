// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include <bits/stdc++.h>
using namespace std;
vector<int> JobSequencing(vector<int> &id, vector<int> &d, vector<int> &p)
{
  int n = id.size();
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, d[i]);
  }
  vector<priority_queue<int>> m(maxi + 1);
  for (int i = 0; i < n; i++)
  {
    m[d[i]].push(p[i]);
  }
  priority_queue<int> pq;
  int jobCount = 0, totalProfit = 0;
  for (int i = maxi; i >= 1; i--)
  {
    while (!m[i].empty())
    {
      pq.push(m[i].top());
      m[i].pop();
    }
    if (!pq.empty())
    {
      totalProfit += pq.top();
      pq.pop();
      jobCount++;
    }
  }
  return {maxi, totalProfit};
}
int main()
{
  return 0;
}