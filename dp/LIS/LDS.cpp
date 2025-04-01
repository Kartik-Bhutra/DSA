// https://leetcode.com/problems/largest-divisible-subset/
#include <bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &a)
{
  int n = a.size();
  sort(a.begin(), a.end());
  vector<int> dp(n, 1);
  vector<int> pre(n, -1);
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (a[i] % a[j] == 0 && dp[i] <= dp[j])
      {
        dp[i] = dp[j] + 1;
        pre[i] = j;
      }
    }
  }
  vector<int> ans;
  int maxi = max_element(dp.begin(), dp.end()) - dp.begin();
  while (maxi != -1)
  {
    ans.push_back(a[maxi]);
    maxi = pre[maxi];
  }
  return ans;
}
int main()
{

  return 0;
}