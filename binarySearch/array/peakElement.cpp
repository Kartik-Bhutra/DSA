// https://leetcode.com/problems/find-peak-element/description/
#include <bits/stdc++.h>
using namespace std;
int peakElement(vector<int> &arr)
{
  int n = arr.size() - 1;
  if (n == 0 || arr[0] > arr[1])
    return 0;
  if (arr[n] > arr[n - 1])
    return n;
  int low = 1, high = n - 1;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      return mid;
    if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main()
{
  vector<int> arr = {1, 2, 3, 1};
  // time complexity is O(N) and space complexity is O(1) with duplicates
  // without duplicates time complexity is O(Log(N))
  cout << arr[peakElement(arr)] << "\n";
  return 0;
}