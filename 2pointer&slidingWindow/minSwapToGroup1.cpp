// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minSwaps(vector<int> &nums)
  {
    int n = nums.size();
    int one = 0;
    for (int num : nums)
      one += num;
    int newone = 0;
    for (int i = 0; i < one; i++)
    {
      newone += nums[i];
    }
    int ans = one - newone;
    for (int i = one; i < 2 * n; i++)
    {
      newone += nums[i % n];
      newone -= nums[(i - one) % n];
      ans = min(ans, one - newone);
    }
    return ans;
  }
};
int main()
{

  return 0;
}