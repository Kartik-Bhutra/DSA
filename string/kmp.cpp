#include <bits/stdc++.h>
using namespace std;
vector<int> computeLPS(const string &pattern)
{
  int n = pattern.size();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++)
  {
    int prev_idx = lps[i - 1];
    while (prev_idx > 0 && pattern[i] != pattern[prev_idx])
    {
      prev_idx = lps[prev_idx - 1];
    }
    lps[i] = prev_idx + (pattern[i] == pattern[prev_idx] ? 1 : 0);
  }
  return lps;
}
vector<int> searchPattern(const string &text, const string &pattern)
{
  string combined = pattern + "#" + text;
  vector<int> lps = computeLPS(combined);
  vector<int> occurrences;
  for (int i = pattern.size(); i < lps.size(); i++)
  {
    if (lps[i] == pattern.size())
    {
      int startIdx = i - 2 * pattern.size();
      if (startIdx >= 0)
      {
        occurrences.push_back(startIdx);
      }
    }
  }
  return occurrences;
}
int kmp(string String, string pattern)
{
  int i = 0, j = 0, m = pattern.length(), n = String.length();
  pattern = ' ' + pattern;
  vector<int> piTable(m + 1, 0);
  for (int i = 2; i <= m; i++)
  {
    while (j <= m && pattern[j + 1] == pattern[i])
      piTable[i++] = ++j;
    j = 0;
  }
  j = 0;
  for (int i = 0; i < n; i++)
  {
    if (pattern[j + 1] != String[i])
    {
      while (j != 0 && pattern[j + 1] != String[i])
        j = piTable[j];
    }
    j++;
    if (j == m)
      return i - m + 1;
  }
  return -1;
}
int main()
{
  return 0;
}