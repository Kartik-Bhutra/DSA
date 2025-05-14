// https://leetcode.com/problems/first-missing-positive/
#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &a)
{
  int n = a.size();
  for (int i = 1; i <= n; i++)
  {
    int j = a[i - 1];
    while (j > 0 && j <= n && a[j - 1] != j)
    {
      swap(a[i - 1], a[j - 1]);
      j = a[i - 1];
    }
  }
  int ans = n + 1;
  for (int i = 1; i <= n; i++)
  {
    if (a[i - 1] != i)
    {
      return i;
    }
  }
  return ans;
}
int main()
{

  return 0;
}