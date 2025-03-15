// https://leetcode.com/problems/non-overlapping-intervals/description/
#include <bits/stdc++.h>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>> &t)
{
  int n = t.size();
  sort(t.begin(), t.end(), [](const vector<int> &a, const vector<int> &b)
       { return a[1] < b[1]; });
  int p = 0;
  int ct = 1;
  for (int i = 1; i < n; i++)
  {
    if (t[i][0] >= t[p][1])
    {
      p = i;
      ct++;
    }
  }
  return n - ct;
}
int main()
{
  return 0;
}