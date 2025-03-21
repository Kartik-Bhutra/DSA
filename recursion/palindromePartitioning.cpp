// https://leetcode.com/problems/palindrome-partitioning/description/
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;
void party(string s, vector<string> vec, int start)
{
  if (!s[start])
  {
    ans.push_back(vec);
    return;
  }
  string temp = "";
  for (int i = start; s[i]; i++)
  {
    temp += s[i];
    bool val = 1;
    for (int j = 0; j <= (i - start) / 2; j++)
    {
      if (temp[j] != temp[i - start - j])
      {
        val = 0;
        break;
      }
    }
    if (val)
    {
      vec.push_back(temp);
      party(s, vec, i + 1);
      vec.pop_back();
    }
  }
}
vector<vector<string>> partition(string s)
{
  vector<string> vec;
  party(s, vec, 0);
  return ans;
}
int main()
{
  return 0;
}