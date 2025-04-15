// https://leetcode.com/problems/shortest-palindrome/description/
#include <bits/stdc++.h>
using namespace std;
int kmp(const string &txt, const string &patt)
{
  string newString = patt + '#' + txt;
  vector<int> pi(newString.length(), 0);
  int i = 1, k = 0;
  while (i < newString.length())
  {
    if (newString[i] == newString[k])
    {
      k++;
      pi[i] = k;
      i++;
    }
    else
    {
      if (k > 0)
      {
        k = pi[k - 1];
      }
      else
      {
        pi[i] = 0;
        i++;
      }
    }
  }
  return pi.back();
}
string shortestPalindrome(string s)
{
  int count = kmp(string(s.rbegin(), s.rend()), s);
  return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
}
string shortestPalindrome(string s)
{
  int n = s.size();
  if (n == 0)
    return "";
  long long prefix = 0;
  long long suffix = 0;
  long long base = 29;
  int last = 0;
  long long power = 1;
  long long mod = 1e9 + 7;
  string temp = "";

  for (int i = 0; i < n; i++)
  {
    long long ch = s[i] - 'a' + 1;
    prefix = (prefix * base) % mod;
    prefix = (prefix + ch) % mod;
    suffix = (suffix + ch * power) % mod;
    power = (power * base) % mod;

    if (prefix == suffix)
    {
      last = i;
    }
  }
  temp = s.substr(last + 1);
  reverse(temp.begin(), temp.end());
  return temp + s;
}
int main()
{

  return 0;
}