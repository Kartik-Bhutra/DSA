// https://leetcode.com/problems/edit-distance/description/
#include <bits/stdc++.h>
using namespace std;
int minDistance(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();
  vector<int> prev(m + 1, 0);
  vector<int> cur(m + 1, 0);
  for (int j = 0; j <= m; j++)
  {
    prev[j] = j;
  }
  for (int i = 1; i <= n; i++)
  {
    cur[0] = i;
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        cur[j] = prev[j - 1];
      }
      else
      {
        cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
      }
    }
    prev = cur;
  }
  return cur[m];
}
int main()
{
  return 0;
}