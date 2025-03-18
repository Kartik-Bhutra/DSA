// https://www.naukri.com/code360/problems/distinct-characters_2221410
#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &s)
{
  vector<int> m(26, 0);
  auto ch = [&]() -> bool
  {
    int a = 0;
    for (int i = 0; i < 26; i++)
    {
      if (m[i])
        a++;
    }
    return (a <= k);
  };
  int i = 0, j = 0, r = 0;
  while (s[j])
  {
    m[s[j] - 'a']++;
    j++;
    if (ch())
    {
      r = max(r, j - i + 1);
    }
    else
    {
      while (i < j)
      {
        m[s[i] - 'a']--;
        i++;
        if (ch())
        {
          break;
        }
      }
    }
  }
  return r;
}
int main()
{
  return 0;
}