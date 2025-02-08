// https://leetcode.com/problems/sort-colors/description/
#include <bits/stdc++.h>
using namespace std;
void sort3Colors(vector<int> &arr)
{
  int zeroIdx = 0, oneIdx = 0, twoIdx = arr.size() - 1;
  while (oneIdx <= twoIdx)
  {
    // placing all zeros at starting
    if (arr[oneIdx] == 0)
    {
      swap(arr[zeroIdx], arr[oneIdx]);
      zeroIdx++;
      oneIdx++;
    }
    // keep incresing also for zeros and ones
    else if (arr[oneIdx] == 1)
    {
      oneIdx++;
    }
    else
    {
      // swaping with last so mid remains same for checking
      swap(arr[oneIdx], arr[twoIdx]);
      twoIdx--;
    }
  }
}
int main()
{
  vector<int> arr = {0, 0, 0, 1, 2, 0, 1, 2, 0, 2, 1, 2, 2, 0, 1, 2, 1, 1, 0};
  sort3Colors(arr);
  // time complexity is O(N) and space complexity is O(1)
  [&]()
  {
    for (int i : arr)
      cout << i << " ";
    cout << "\n";
  }();
  return 0;
}