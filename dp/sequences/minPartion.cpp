// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// https://www.geeksforgeeks.org/meet-in-the-middle/
#include <bits/stdc++.h>
using namespace std;
int minimumDifference(vector<int> &nums)
{
  int n = nums.size(), res = 0, sum = 0;
  sum = accumulate(nums.begin(), nums.end(), 0);
  int N = n / 2;
  vector<vector<int>> left(N + 1), right(N + 1);
  for (int mask = 0; mask < (1 << N); ++mask)
  {
    int sz = 0, l = 0, r = 0;
    for (int i = 0; i < N; ++i)
    {
      if (mask & (1 << i))
      {
        sz++;
        l += nums[i];
        r += nums[i + N];
      }
    }
    left[sz].push_back(l);
    right[sz].push_back(r);
  }
  for (int sz = 0; sz <= N; ++sz)
  {
    sort(right[sz].begin(), right[sz].end());
  }
  res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));
  for (int sz = 1; sz < N; ++sz)
  {
    for (auto &a : left[sz])
    {
      int b = (sum - 2 * a) / 2, rsz = N - sz;
      auto &v = right[rsz];
      auto itr = lower_bound(v.begin(), v.end(), b);
      if (itr != v.end())
        res = min(res, abs(sum - 2 * (a + (*itr))));
      if (itr != v.begin())
      {
        auto it = itr;
        --it;
        res = min(res, abs(sum - 2 * (a + (*it))));
      }
    }
  }
  return res;
}
int main()
{
  return 0;
}