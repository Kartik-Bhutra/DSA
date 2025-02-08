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
}

int main()
{
  vector<int> arr = {0, 1, 2, 4, 5};
  // time complexity is O(Log(N)) and space complexity is O(1)
  cout << minimumElement(arr) << "\n";
  return 0;
}