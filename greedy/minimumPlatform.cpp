// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include <bits/stdc++.h>
using namespace std;
int findPlatform(vector<int> &a, vector<int> &d)
{
  int n = a.size();
  vector<pair<int, int>> ad;
  for (int i = 0; i < n; i++)
  {
    ad.push_back({a[i], d[i]});
  }
  sort(ad.begin(), ad.end());
  vector<int> p = {ad[0].second};
  for (int i = 1; i < n; i++)
  {
    bool v = 1;
    for (int j = 0; j < p.size(); j++)
    {
      if (p[j] < ad[i].first)
      {
        v = 0;
        p[j] = ad[i].second;
        break;
      }
    }
    if (v)
    {
      p.push_back(ad[i].second);
    }
  }
  return p.size();
}
int main()
{
  vector<int> a = {2112, 258, 1645, 1608, 2144}, d = {2307, 1738, 1714, 1907, 2235};
  findPlatform(a, d);
  return 0;
}