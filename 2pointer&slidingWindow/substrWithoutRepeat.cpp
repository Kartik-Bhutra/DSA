// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
  vector<bool> mp(128, 0);
  int r = 0, i = 0, j = 0;
  while (s[j])
  {
    if (mp[s[j]])
    {
      while (i <= j && s[i] != s[j])
      {
        mp[s[i]] = 0;
        i++;
      }
      i++;
      j++;
    }
    else
    {
      mp[s[j]] = 1;
      j++;
      r = max(r, j - i + 1);
    }
  }
  return r;
}
int lengthOfLongestSubstring1(string s)
{
  vector<int> mp(256, -1);
  int l = 0, r = 0;
  int n = s.size();
  int len = 0;
  while (r < n)
  {
    if (mp[s[r]] != -1)
    {
      l = max(mp[s[r]] + 1, l);
    }

    mp[s[r]] = r;
    len = max(len, r - l + 1);
    r++;
  }
  return len;
}
int main()
{

  return 0;
}