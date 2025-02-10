// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/0
#include <bits/stdc++.h>
using namespace std;
double minimumMaxGasDistance(vector<int> &arr, int k)
{
  int n = arr.size();
  double low = 0, high = 1e9;
  double tolerance = 1e-6;
  while (high - low >= tolerance)
  {
    double mid = (double)(high + low) / 2;
    int stations = 0;
    for (int i = 1; i < n; i++)
    {
      if (arr[i] - arr[i - 1] > mid)
        stations += (arr[i] - arr[i - 1]) / mid;
    }
    if (stations <= k)
      high = mid;
    else
      low = mid;
  }
  return high;
}
int main()
{
  vector<int> arr = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
  // time complexity is O(Log(1e15)) and space complexity is O(1)
  cout << minimumMaxGasDistance(arr, 2) << "\n";
  return 0;
}