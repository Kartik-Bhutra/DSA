#include <bits/stdc++.h>
using namespace std;
vector<int> rabinKarp(const string &text, const string &pattern)
{
  const int base = 256;
  const int mod = 101;
  int n = text.size();
  int m = pattern.size();
  vector<int> result;
  if (m > n)
    return result;
  int h = 1;
  for (int i = 0; i < m - 1; i++)
    h = (h * base) % mod;
  int pHash = 0;
  int tHash = 0;
  for (int i = 0; i < m; i++)
  {
    pHash = (base * pHash + pattern[i]) % mod;
    tHash = (base * tHash + text[i]) % mod;
  }
  for (int i = 0; i <= n - m; i++)
  {
    if (pHash == tHash)
    {
      if (text.substr(i, m) == pattern)
        result.push_back(i);
    }
    if (i < n - m)
    {
      tHash = (base * (tHash - text[i] * h) + text[i + m]) % mod;
      if (tHash < 0)
        tHash += mod;
    }
  }
  return result;
}
int main()
{
  return 0;
}