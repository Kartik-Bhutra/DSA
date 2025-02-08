// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> &arr)
{
  int left = 0, right = arr.size() - 1;
  while (left < right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] < arr[right])
    {
      right = mid;
    }
    else if (arr[mid] > arr[right])
    {
      left = mid + 1;
    }
    else
    {
      right--;
    }
  }
  return left;
}
int main()
{
  vector<int> arr = {2, 2, 2, 0, 1};
  // time complexity is O(N) and space complexity is O(1) with duplicates
  // without duplicates time complexity is O(Log(N))
  cout << arr[pivotIndex(arr)] << "\n";
  return 0;
}