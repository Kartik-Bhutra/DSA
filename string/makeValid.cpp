// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
#include <bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string s)
{
  int ans = 0, neg = 0, t = 0;
  for (int i = 0; s[i]; i++)
  {
    if (s[i] == '(')
      t++;
    else
      t--;
    if (t < 0)
    {
      ans++;
      t = 0;
    }
  }
  if (t > 0)
    ans += t;
  return ans;
}
int main()
{

  return 0;
}