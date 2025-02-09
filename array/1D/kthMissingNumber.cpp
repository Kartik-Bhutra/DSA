// https://leetcode.com/problems/kth-missing-positive-number/description/
#include <bits/stdc++.h>
using namespace std;
int KthMissingInteger(vector<int> &arr, int k)
{
  int n = arr.size() - 1;
  int num = 1, missing = 0;
  for (int i = 1; num <= n; i++)
  {
    if (arr[n] == i)
      n++;
    else
    {
      missing++;
      if (missing == k)
        return i;
    }
  }
  return arr[n] + k - missing;
}

int kthMissingInteger(vector<int> &arr, int k)
{
  int low = 0, high = arr.size() - 1;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    // how many are missing
    int missing = arr[mid] - mid - 1;
    if (missing < k)
      low = mid + 1;
    else
    {
      high = mid - 1;
    }
  }
  return low + k;
}

int main()
{
  vector<int> arr = {2, 3, 4, 7, 11};
  // time complexity is O(Log(N)) and space complexity is O(1)
  cout << kthMissingInteger(arr, 5) << "\n";
  return 0;
}
