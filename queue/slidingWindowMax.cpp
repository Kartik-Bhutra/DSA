// https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
  int n = arr.size();
  deque<pair<int, int>> dq;
  vector<int> ans(n - k + 1);
  for (int i = n - 1; i > n - k; i--)
  {
    while (!dq.empty() && dq.back().first <= arr[i])
    {
      dq.pop_back();
    }
    dq.push_back({arr[i], i});
  }
  for (int i = n - k; i >= 0; i--)
  {
    if (dq.front().second - i >= k)
      dq.pop_front();
    ans[i] = max(dq.front().first, arr[i]);
    while (!dq.empty() && dq.back().first <= arr[i])
    {
      dq.pop_back();
    }
    dq.push_back({arr[i], i});
  }
  return ans;
}
int main()
{
  // time complexity is O(N) and space complexity is O(N)
  return 0;
}