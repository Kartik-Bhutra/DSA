// https://leetcode.com/problems/unique-paths/description/
#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n)
{
  if (m > n)
  {
    swap(m, n);
  }
  long long term = 1;
  for (int i = 1; i < m; i++)
  {
    term *= (m + n - 1 - i);
    term /= i;
  }
  return term;
}
int main()
{
  return 0;
}