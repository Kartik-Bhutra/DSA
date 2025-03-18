#include <bits/stdc++.h>
using namespace std;
int subarraysWithKDistinct(vector<int> &arr, int k)
{
  int n = arr.size();
  auto fx = [&](int k) -> int
  {
    unordered_map<int, int> mp;
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
      mp[arr[i]]++;
      while (mp.size() > k && j < i)
      {
        mp[arr[j]]--;
        if (mp[arr[j]] == 0)
          mp.erase(arr[j]);
        j++;
      }
      if (mp.size() == k)
        ans += i - j + 1;
    }
    return ans;
  };
  return fx(k) - fx(k - 1);
}
int kDistinct(vector<int> &nums, int k)
{
  vector<int> distinctCount(nums.size() + 1, 0);
  int totalCount = 0;
  int left = 0;
  int right = 0;
  int currCount = 0;
  while (right < nums.size())
  {
    if (++distinctCount[nums[right++]] == 1)
    {
      k--;
    }
    if (k < 0)
    {
      --distinctCount[nums[left++]];
      k++;
      currCount = 0;
    }
    if (k == 0)
    {
      while (distinctCount[nums[left]] > 1)
      {
        --distinctCount[nums[left++]];
        currCount++;
      }
      totalCount += (currCount + 1);
    }
  }
  return totalCount;
}
int main()
{
  return 0;
}