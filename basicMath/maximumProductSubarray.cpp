// https://leetcode.com/problems/maximum-product-subarray/
#include <bits/stdc++.h>
using namespace std;
int maximumProductSubarray(vector<int> &nums)
{
  int minimum = nums[0];
  int maximum = nums[0];
  int n = nums.size();
  int result = maximum;
  for (int i = 1; i < n; i++)
  {
    int temp = max(nums[i], max(nums[i] * minimum, nums[i] * maximum));
    minimum = min(nums[i], min(nums[i] * minimum, nums[i] * maximum));
    maximum = temp;
    result = max(result, maximum);
  }
  return result;
}
int main()
{
  vector<int> nums = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 0};
  // time complexity is O(N) and space complexity is O(1)
  cout << maximumProductSubarray(nums) << "\n";
  return 0;
}