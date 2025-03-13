// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;
int maxMeetings(vector<int> &s, vector<int> &e)
{
  int n = s.size();
  vector<pair<int, int>> es;
  for (int i = 0; i < n; i++)
  {
    es.push_back({e[i], s[i]});
  }
  sort(es.begin(), es.end(), [](const pair<int, int> &a, const pair<int, int> &b)
       { return a.first < b.first; });
  int ans = 0, last = -1;
  for (int i = 0; i < n; i++)
  {
    if (es[i].second > last)
    {
      ans++;
      last = es[i].first;
    }
  }
  return ans;
}
int main()
{
  vector<int> s = {1, 3, 0, 5, 8, 5}, e = {2, 4, 6, 7, 9, 9};
  maxMeetings(s, e);
  return 0;
}