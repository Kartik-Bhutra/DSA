// https://www.naukri.com/code360/problems/minimum-window-subsequence_2181133
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
  auto ch = [&](int i, int j) -> bool
  {
    int d = 0;
    for (int k = j; k <= i; k++)
    {
      if (t[d])
      {
        if (t[d] == s[k])
        {
          d++;
        }
      }
      else
      {
        return true;
      }
    }
    if (t[d])
      return false;
    return true;
  };
  int j = 0, ans = INT_MAX, ansj = -1;
  for (int i = 0; s[i]; i++)
  {
    if (ch(i, j))
    {
      if (i - j + 1 < ans)
      {
        ans = i - j + 1;
        ansj = j;
      }
    }
    while (j < i && ch(i, j))
    {
      if (i - j + 1 < ans)
      {
        ans = i - j + 1;
        ansj = j;
      }
      j++;
    }
  }
  return ans == INT_MAX ? "" : s.substr(ansj, ans);
}
int main()
{

  return 0;
}