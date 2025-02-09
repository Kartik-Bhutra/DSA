// https://leetcode.com/problems/split-array-largest-sum/description/
#include <bits/stdc++.h>
using namespace std;
int splitArray(vector<int> &arr, int k)
{
  int n = arr.size();
  int low = *max_element(arr.begin(), arr.end()), high = 1e9;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    int splits = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += arr[i];
      if (sum > mid)
      {
        splits++;
        sum = arr[i];
      }
    }
    if (splits > k)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
int main()
{
  vector<int> arr = {7, 2, 5, 10, 8};
  // time complexity is O(N*Log(N)) and space complexity is O(N)
  cout << splitArray(arr, 2) << "\n";
  return 0;
}