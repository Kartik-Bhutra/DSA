#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
  int i = 0, j = 0;
  vector<int> mp(26, 0);
  int ans = 0;
  int maxFreq = 0;
  int n = s.length();
  while (j < n)
  {
    mp[s[j] - 'A']++;
    maxFreq = max(maxFreq, mp[s[j] - 'A']);
    if ((j - i + 1) - maxFreq > k)
    {
      mp[s[i] - 'A']--;
      i++;
    }
    else
      ans = max(ans, (j - i + 1));
    j++;
  }
  return ans;
}
int main()
{
  return 0;
}