// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/
#include <bits/stdc++.h>
using namespace std;
vector<string> validStrings(int n)
{
  vector<string> a;
  function<void(int, string)> r = [&](int i, string s)
  {
    if (i == n)
    {
      a.push_back(s);
      return;
    }
    if (i > 0)
    {
      if (s[i - 1] != '0')
        r(i + 1, s + '0');
      r(i + 1, s + '1');
    }
    else
    {
      r(i + 1, s + '0');
      r(i + 1, s + '1');
    }
  };
  r(0,"");
  return a;
}
int main()
{

  return 0;
}