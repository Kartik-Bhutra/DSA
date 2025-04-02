// https://leetcode.com/problems/rotate-string/description/
#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
  string s2 = s + s;
  return (s.length() != goal.length()) ? 0 : s2.find(goal) != string::npos;
}
int main()
{

  return 0;
}