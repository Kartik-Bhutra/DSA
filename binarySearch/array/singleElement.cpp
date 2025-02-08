#include <bits/stdc++.h>
using namespace std;
int singleElement(vector<int> &arr)
{
  int n = arr.size() - 1;
  int high = n, low = 0;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    if (mid > 0 && arr[mid] == arr[mid - 1])
    {
      if ((mid + 1) % 2)
        high = mid;
      else
        low = mid + 1;
    }
    else if (mid < n && arr[mid] == arr[mid + 1])
    {
      if ((n - mid + 1) % 2)
        low = mid;
      else
        high = mid - 1;
    }
    else
      return arr[mid];
  }
  return -1;
}
int main()
{
  vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  // time complexity is O(Log(N)) and space complexity is O(1)
  cout << singleElement(arr) << "\n";
  return 0;
}