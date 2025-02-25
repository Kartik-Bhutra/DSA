#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
  string ans;
  for (char digit : num)
  {
    while (!ans.empty() && ans.back() > digit && k > 0)
    {
      ans.pop_back();
      k--;
    }
    if (!ans.empty() || digit != '0')
      ans.push_back(digit);
  }
  while (!ans.empty() && k > 0)
  {
    ans.pop_back();
    k--;
  }
  return ans.empty() ? "0" : ans;
}
int main()
{
  string num = "5432219";
  return 0;
}