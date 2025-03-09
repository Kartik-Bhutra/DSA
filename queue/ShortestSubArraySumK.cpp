// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
#include <bits/stdc++.h>
using namespace std;
int shortestSubarray(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<pair<int, int>> pre;
  long long temp = 0;
  for (int i = 0; i < n; i++)
  {
    temp += arr[i];
    pre.push_back({temp, i});
  }
  sort(pre.begin(), pre.end());
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (pre[i].first >= k)
      ans = min(ans, pre[i].second + 1);
  }
  int i = 0, j = 0;
  while (i <= j && j < n)
  {
    if (pre[j].first - pre[i].first < k)
      j++;
    else
    {
      ans = min(ans, abs(pre[j].second - pre[i].second));
      i++;
    }
  }
  return ans == INT_MAX ? -1 : ans;
}
int main()
{

  return 0;
}