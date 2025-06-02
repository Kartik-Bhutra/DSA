// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  const int MOD = 1e9 + 7;
  unordered_map<string, int> memo;
  int solve(unordered_map<int, vector<int>> &mp, unordered_map<int, vector<int>>::iterator it, int bitmask, int n)
  {
    if (bitmask == (1 << n) - 1)
      return 1;
    if (it == mp.end())
      return 0;
    string key = to_string(bitmask) + "_" + to_string(it->first);
    if (memo.count(key))
      return memo[key];
    int ans = solve(mp, next(it), bitmask, n) % MOD;
    for (int j : it->second)
    {
      if (!(bitmask & (1 << j)))
      {
        bitmask |= (1 << j);
        ans = (ans + solve(mp, next(it), bitmask, n)) % MOD;
        bitmask ^= (1 << j);
      }
    }
    return memo[key] = ans;
  }

public:
  int numberWays(vector<vector<int>> &hats)
  {
    int n = hats.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i)
    {
      for (int h : hats[i])
      {
        mp[h].push_back(i);
      }
    }
    return solve(mp, mp.begin(), 0, n);
  }
};
class Solution
{
public:
  int numberWays(vector<vector<int>> &hats)
  {
    vector<vector<int>> persons(40);
    const int n(hats.size()), mod(1e9 + 7);
    vector<int> masks(1 << n);
    masks[0] = 1;
    for (int i = 0; i < n; ++i)
      for (const int &h : hats[i])
        persons[h - 1].emplace_back(i);
    for (int i = 0; i < 40; ++i)
      for (int j = (1 << n) - 1; j >= 0; --j)
        for (const int &p : persons[i])
          if ((j & (1 << p)) == 0)
          {
            masks[j | (1 << p)] += masks[j];
            masks[j | (1 << p)] %= mod;
          }
    return masks[(1 << n) - 1];
  }
};
int main()
{
  return 0;
}