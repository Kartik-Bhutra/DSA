// https://leetcode.com/problems/reverse-words-in-a-string/description/
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
  reverse(s.begin(), s.end());
  int n = s.size();
  int left = 0;
  int right = 0;
  int i = 0;
  while (i < n)
  {
    while (i < n && s[i] == ' ')
      i++;
    if (i == n)
      break;
    while (i < n && s[i] != ' ')
    {
      s[right++] = s[i++];
    }
    reverse(s.begin() + left, s.begin() + right);
    s[right++] = ' ';
    left = right;
    i++;
  }
  s.resize(right - 1);
  return s;
}
int main()
{

  return 0;
}