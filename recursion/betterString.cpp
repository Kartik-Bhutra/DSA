// https://www.geeksforgeeks.org/problems/better-string/1
#include <bits/stdc++.h>
using namespace std;
string betterString(string s1, string s2)
{
  auto r = [](string s) -> int
  {
    unordered_map<char, int> last;
    int count = 1;
    for (auto ch : s)
    {
      int newCount = 2 * count;
      if (last.find(ch) != last.end())
        newCount -= last[ch];
      last[ch] = count;
      count = newCount;
    }
    return count;
  };
  return r(s1) > r(s2) ? s2 : s1;
}
int main()
{
  return 0;
}