// https://leetcode.com/problems/count-good-numbers/
#include <bits/stdc++.h>
using namespace std;
int countGoodNumbers(long long n)
{
  long long e = (n + 1) / 2, o = n / 2;
  long long m = 1e9 + 7;
  auto mp = [&m](long long x, long long y) -> long long
  {
    long long r = 1, t = x;
    while (y)
    {
      if (y & 1)
      {
        r = (r * t) % m;
      }
      t = (t * t) % m;
      y = y >> 1;
    }
    return r;
  };
  return (mp(5, e) * mp(4, o)) % m;
}
int main()
{
  return 0;
}