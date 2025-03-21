#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool wordBreak(string s, vector<string> &w)
  {
    unordered_set<string> st(w.begin(), w.end());
    unordered_set<int> visited;
    function<bool(int)> r = [&](int i)
    {
      if (i == s.size())
        return true;
      if (visited.count(i))
        return false;
      string t = "";
      for (int j = i; j < s.size(); j++)
      {
        t += s[j];
        if (st.count(t) && r(j + 1))
          return true;
      }
      visited.insert(i);
      return false;
    };
    return r(0);
  }
};
int main()
{
  return 0;
}