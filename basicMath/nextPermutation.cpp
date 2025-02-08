// https://leetcode.com/problems/next-permutation/
#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    // index where decreasing sequence break
    int pivotIdx = [&]() -> int
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
                return i - 1;
        }
        return -1;
    }();
    if (pivotIdx >= 0)
    {
        // find just greater than the pivot and as the sequence is decreasing so stop at once
        for (int i = n - 1; i > pivotIdx; i--)
        {
            if (nums[pivotIdx] < nums[i])
            {
                swap(nums[pivotIdx], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + pivotIdx + 1, nums.end());
    }
    else
    {
        // if this permutation is largest then starting point is next
        reverse(nums.begin(), nums.end());
    }
}
int main()
{
    vector<int> nums = {3, 2, 1};
    nextPermutation(nums);
    // time complexity is O(N) and space complexity is O(1)
    [&]()
    {
        for (int i : nums)
            cout << i << " ";
        cout << "\n";
    }();
    return 0;
}