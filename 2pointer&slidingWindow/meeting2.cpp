// https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
#include <bits/stdc++.h>
using namespace std;
int minMeetingRooms(vector<int> &start, vector<int> &end)
{
  int n = start.size();
  int room = 0;
  int res = 0;
  sort(start.begin(), start.end());
  sort(end.begin(), end.end());
  int i = 0, j = 0;
  while (i < start.size())
  {
    if (start[i] < end[j])
    {
      room++;
      i++;
    }
    else
    {
      room--;
      j++;
    }
    res = max(res, room);
  }
  return res;
}
class Solution
{
public:
  int minMeetingRooms(vector<int> &start, vector<int> &end)
  {
    int n = start.size();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
      a[i] = {start[i], end[i]};
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a[0].second);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
      while (pq.size() && pq.top() <= a[i].first)
        pq.pop();
      pq.push(a[i].second);
      ans = max(ans, (int)pq.size());
    }
    return ans;
  }
};
int main()
{
  vector<int> start = {2, 9, 6};
  vector<int> end = {4, 12, 10};
  cout << minMeetingRooms(start, end);
  return 0;
}