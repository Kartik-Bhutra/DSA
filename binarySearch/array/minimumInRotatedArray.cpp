// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;
int minimumElement(vector<int> &arr)
{
  int n = arr.size();
  int high = n - 1, low = 0;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    if (arr[mid] < arr[0])
      high = mid - 1;
    else
      low = mid + 1;
  }
  high = (high + 1) % n;
  return arr[high];
}
int minimumElementDuplicate(vector<int> &arr)
{
  int low = 0, high = arr.size() - 1;
  int ans = INT_MAX;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    if (arr[mid] == arr[low] && arr[mid] == arr[high])
    {
      low++;
      high--;
    }
    if (arr[low] <= arr[mid])
    {
      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    else if (arr[mid] <= arr[high])
    {
      ans = min(ans, arr[mid]);
      high = mid - 1;
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {0, 1, 2, 4, 5};
  // time complexity is O(N) and space complexity is O(1) with duplicates
  // without duplicates time complexity is O(Log(N))
  cout << minimumElement(arr) << "\n";
  return 0;
}