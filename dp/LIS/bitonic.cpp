// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
#include <bits/stdc++.h>
using namespace std;
int LongestBitonicSequence(int n, vector<int> &a1)
{
  vector<int> a2 = a1;
  reverse(a2.begin(), a2.end());
  auto LIS = [](vector<int> &a) -> vector<int>
  {
    vector<int> dp;
    int n = a.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
      int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
      if (j == dp.size())
      {
        dp.push_back(a[i]);
      }
      else
      {
        dp[j] = a[i];
      }
      res[i] = j + 1;
    }
    return res;
  };
  vector<int> l1 = LIS(a1), l2 = LIS(a2);
  int maxi = -1;
  for (int i = 0; i < n; i++)
  {
    if (l1[i] > 1 && l2[n - i - 1] > 1)
      maxi = max(l1[i] + l2[n - i - 1] - 1, maxi);
  }
  return maxi;
}
int main()
{

  return 0;
}