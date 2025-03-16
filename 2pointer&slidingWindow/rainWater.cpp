// https://leetcode.com/problems/trapping-rain-water/description/
#include <bits/stdc++.h>
using namespace std;
int rainWater(vector<int> &arr)
{
  int low = 0, high = arr.size() - 1;
  int leftMax = arr[low], rightMax = arr[high];
  int ans = 0;
  while (low < high)
  {
    if (leftMax < rightMax)
    {
      low++;
      if (arr[low] < leftMax)
        ans += leftMax - arr[low];
      else
        leftMax = arr[low];
    }
    else
    {
      high--;
      if (rightMax > arr[high])
        ans += rightMax - arr[high];
      else
        rightMax = arr[high];
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << rainWater(arr);
  // time complexity O(N) and space complexity O(N)
  return 0;
}