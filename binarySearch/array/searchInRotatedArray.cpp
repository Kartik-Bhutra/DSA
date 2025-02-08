// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <bits/stdc++.h>
using namespace std;
bool find(vector<int> &arr, int target)
{
  int low = 0, high = arr.size() - 1;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    if (arr[mid] == target)
      return true;
    if (arr[low] == arr[mid] && arr[mid] == arr[high])
    {
      low++;
      high--;
    }
    else if (arr[mid] >= arr[low])
    {
      if (arr[mid] > target && arr[low] <= target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    else
    {
      if (arr[mid] < target && arr[high] >= target)
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return false;
}
int main()
{
  vector<int> arr = {1, 0, 1, 1, 1};
  // time complexity is O(N) and space complexity is O(1) with duplicates
  // without duplicates time complexity is O(Log(N))
  cout << find(arr, 10) << "\n";
  return 0;
}