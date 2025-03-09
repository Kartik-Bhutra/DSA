// https://leetcode.com/problems/valid-parenthesis-string/description/
#include <bits/stdc++.h>
using namespace std;
bool checkValidString(string s)
{
  int mini = 0, maxi = 0;
  for (int i = 0; s[i]; i++)
  {
    if (s[i] == '(')
    {
      mini++;
      maxi++;
    }
    else if (s[i] == ')')
    {
      mini = max(0, mini - 1);
      maxi--;
      if (maxi < 0)
        return false;
    }
    else
    {
      mini = max(0, mini - 1);
      maxi++;
    }
  }
  if (!mini)
    return true;
  return false;
}
int main()
{
  return 0;
}