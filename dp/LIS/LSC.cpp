// https://leetcode.com/problems/longest-string-chain/description/
#include <bits/stdc++.h>
using namespace std;
int longestStrChain(vector<string> &a)
{
  unordered_map<std::string, int> mp;
  sort(a.begin(), a.end(), [](const std::string &a, const std::string &b)
       { return a.length() < b.length(); });
  for (const std::string &s : a)
  {
    mp[s] = 1;
    for (int i = 0; i < s.length(); i++)
    {
      string t = s.substr(0, i) + s.substr(i + 1);
      if (mp.find(t) != mp.end())
      {
        mp[s] = std::max(mp[s], mp[t] + 1);
      }
    }
  }
  int ans = 0;
  for (const auto &[f, s] : mp)
  {
    ans = max(ans, s);
  }
  return ans;
}
int main()
{
  return 0;
}