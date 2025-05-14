// https://leetcode.com/problems/repeated-string-match/description/
#include <bits/stdc++.h>
using namespace std;
int KMP_search(string s, string p)
{
  int m = s.size();
  int n = p.size();
  vector<int> lps(n, 0);
  int len = 0, i = 1;
  while (i < n)
  {
    if (p[len] == p[i])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  i = 0;
  int j = 0;
  while (i < m and j < n)
  {
    if (s[i] == p[j])
    {
      i++;
      j++;
      if (j == n)
      {
        return true;
      }
    }
    else
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }
  return false;
}
int repeatedStringMatch(string A, string B)
{
  if (A == B)
    return 1;
  int count = 1;
  string source = A;
  while (source.size() < B.size())
  {
    source += A;
    count++;
  }
  if (source == B)
    return count;
  if (KMP_search(source, B) == 1)
    return count;
  if (KMP_search(source + A, B) == 1)
    return count + 1;
  return -1;
}
void computeLPSArray(string &s, vector<int> &lps)
{
  int len = 0, idx = 1;
  lps[0] = 0;
  while (idx < s.length())
  {
    if (s[idx] == s[len])
    {
      len++;
      lps[idx] = len;
      idx++;
    }
    else
    {
      if (len == 0)
      {
        lps[idx] = 0;
        idx++;
      }
      else
      {
        len = lps[len - 1];
      }
    }
  }
}
bool KMPSearch(string &txt, string &pat, vector<int> &lps, int rep)
{
  int n = txt.length(), m = pat.length();
  int i = 0, j = 0;
  while (i < n * rep)
  {
    if (txt[i % n] == pat[j])
    {
      i++;
      j++;
      if (j == m)
      {
        return true;
      }
    }
    else
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
  return false;
}
int minRepeats(string &s1, string &s2)
{
  int n = s1.length();
  int m = s2.length();
  vector<int> lps(m);
  computeLPSArray(s2, lps);
  int x = (m + n - 1) / n;
  if (KMPSearch(s1, s2, lps, x))
    return x;
  if (KMPSearch(s1, s2, lps, x + 1))
    return x + 1;
  return -1;
}
int main()
{
  return 0;
}