#include <bits/stdc++.h>
using namespace std;
int numSubarraysWithSum(vector<int> &arr, int k)
{
  auto slidingWindowAtMost = [&arr](int k)
  {
    int j = 0, crr = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      crr += arr[i];
      while (j <= i && crr > k)
      {
        crr -= arr[j++];
      }
      ans += i - j + 1;
    }
    return ans;
  };
  return slidingWindowAtMost(k) - slidingWindowAtMost(k - 1);
}

int binarySumTarget(vector<int> &nums, int goal)
{
  int start = 0;
  int prefixZeros = 0;
  int currentSum = 0;
  int totalCount = 0;
  for (int end = 0; end < nums.size(); ++end)
  {
    currentSum += nums[end];
    while (start < end && (nums[start] == 0 || currentSum > goal))
    {
      if (nums[start] == 1)
      {
        prefixZeros = 0;
      }
      else
      {
        prefixZeros += 1;
      }
      currentSum -= nums[start];
      start += 1;
    }
    if (currentSum == goal)
    {
      totalCount += 1 + prefixZeros;
    }
  }
  return totalCount;
}
int main()
{
  return 0;
}