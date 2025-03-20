//
#include <bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n)
{
  vector<string> a;
  function<void(int, int, string)> r = [&](int i, int c, string s)
  {
    if (i == 2 * n)
    {
      a.push_back(s);
      return;
    }
    if (c < 2 * n - i)
    {
      r(i + 1, c + 1, s + '(');
      if (c > 0)
        r(i + 1, c - 1, s + ')');
    }
    else
    {
      r(i + 1, c - 1, s + ')');
    }
  };
  r(0, 0, "");
  return a;
}
int main()
{

  return 0;
}