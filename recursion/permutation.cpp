// https://leetcode.com/problems/permutations/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> res;
    backtrack(nums, 0, res);
    return res;
  }

  void backtrack(vector<int> &nums, int start, vector<vector<int>> &res)
  {
    if (start == nums.size())
    {
      res.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); i++)
    {
      swap(nums[start], nums[i]);
      backtrack(nums, start + 1, res);
      swap(nums[start], nums[i]);
    }
  }
};
int main()
{

  return 0;
}