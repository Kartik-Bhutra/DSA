#include <bits/stdc++.h>
using namespace std;
long long countInversion(vector<int> &arr)
{
  return [&](auto &&self, int left, int right) -> long long
  {
    if (left >= right)
      return 0;
    int mid = left + (right - left) / 2;
    long long invCount = self(self, left, mid) + self(self, mid + 1, right);
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
      if (arr[i] <= arr[j])
      {
        temp.push_back(arr[i++]);
      }
      else
      {
        temp.push_back(arr[j++]);
        invCount += (mid - i + 1);
      }
    }
    while (i <= mid)
      temp.push_back(arr[i++]);
    while (j <= right)
      temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++)
      arr[k] = temp[k - left];
    return invCount;
  }([&](auto &&self, int left, int right) -> long long
    {  
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long invCount = self(self, left, mid) + self(self, mid + 1, right);
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
      if (arr[i] <= arr[j]) {
        temp.push_back(arr[i++]);
      } else {
        temp.push_back(arr[j++]);
        invCount += (mid - i + 1);
      }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
    return invCount; }, 0, arr.size() - 1);
}
int main()
{
  vector<int> arr = {1, 20, 6, 4, 5};
  // time complexity is O(N*Log(N)) and space complexity is O(N)
  cout << countInversion(arr) << "\n";
  return 0;
}
