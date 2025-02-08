// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;
pair<int, int> searchIndex(vector<int> &arr, int target)
{
  int n = arr.size() - 1;
  auto bound = [&](bool LU = 0) -> int
  // default upper bound
  {
    int low = 0, high = n, ans = -1;
    while (high >= low)
    {
      int mid = (high + low) / 2;
      if (arr[mid] > target)
        high = mid - 1;
      else if (arr[mid] < target)
        low = mid + 1;
      else
      {
        LU ? low = mid + 1 : high = mid - 1;
        ans = mid;
      }
    }
    return ans;
  };
  int start = bound();
  // if not found
  if (start == -1 || arr[start] != target)
    return {-1, -1};
  else
    return {start, bound(1)};
}
int main()
{
  vector<int> arr = {1, 4, 7, 8, 8, 8, 40, 50};
  pair<int, int> ans = searchIndex(arr, 8);
  // time complexity is O(Log(N)) and space complexity is O(1)
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}