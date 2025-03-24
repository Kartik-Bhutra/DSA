// https://leetcode.com/problems/partition-equal-subset-sum/description/
#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &nums)
{
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 != 0)
    return false;
  int target = sum / 2;
  bitset<10001> bits(1);
  for (int num : nums)
  {
    bits |= (bits << num);
  }
  return bits[target];
}
int main()
{
  return 0;
}