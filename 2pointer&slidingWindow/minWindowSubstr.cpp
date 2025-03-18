#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
  vector<int> m(128, 0);
  for (int i = 0; t[i]; i++)
    m[t[i]]++;
  vector<int> mp(128, 0);
  auto ch = [&]() -> bool
  {
    for (int i = 0; i < 128; i++)
    {
      if (m[i] > 0 && mp[i] < m[i])
      {
        return false;
      }
    }
    return true;
  };
  int ans = INT_MAX, j = 0;
  int ansj = -1;
  for (int i = 0; s[i]; i++)
  {
    mp[s[i]]++;
    while (ch() && j <= i)
    {
      if (i - j + 1 < ans)
      {
        ansj = j;
        ans = i - j + 1;
      }
      mp[s[j]]--;
      j++;
    }
  }
  if (ans == INT_MAX)
    return "";
  return s.substr(ansj, ans);
}
string adjustT(string s, string t)
{
  vector<int> count(128);
  int required = t.length();
  int bestLeft = -1;
  int minLength = s.length() + 1;
  for (const char c : t)
    ++count[c];
  for (int l = 0, r = 0; r < s.length(); ++r)
  {
    if (--count[s[r]] >= 0)
      --required;
    while (required == 0)
    {
      if (r - l + 1 < minLength)
      {
        bestLeft = l;
        minLength = r - l + 1;
      }
      if (++count[s[l++]] > 0)
        ++required;
    }
  }
  return bestLeft == -1 ? "" : s.substr(bestLeft, minLength);
}
int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout << "Minimum window substring: " << minWindow(s, t) << endl;
  return 0;
}