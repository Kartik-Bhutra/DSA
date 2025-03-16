#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
  vector<int> abc(3, 0);
  int l = s.length(), i = 0, j = -1, ans = 0;
  while (i < l)
  {
    abc[s[i] - 'a']++;
    if (abc[0] >= 1 && abc[1] >= 1 && abc[2] >= 1)
    {
      ans += l - i;
      while (j < i - 2)
      {
        j++;
        abc[s[j] - 'a']--;
        if (abc[0] >= 1 && abc[1] >= 1 && abc[2] >= 1)
          ans += l - i;
        else
          break;
      }
    }
    i++;
  }
  return ans;
}
int all3Chars(string s)
{
  int len = s.length();
  vector<int> lastPos = {-1, -1, -1};
  int total = 0;
  for (int pos = 0; pos < len; pos++)
  {
    lastPos[s[pos] - 'a'] = pos;
    total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
  }
  return total;
}
int main()
{
  return 0;
}