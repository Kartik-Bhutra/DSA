// https://leetcode.com/problems/reverse-pairs/description/
#include <bits/stdc++.h>
using namespace std;
int reversePair(vector<int> &arr)
{
  auto pairs = [&](auto &self, int low, int high) -> int
  {
    if (low >= high)
      return 0;
    int mid = low + (high - low) / 2;
    int inversions = self(self, low, mid) + self(self, mid + 1, high);
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
      while (j <= high && (long long)arr[i] > 2LL * arr[j])
        j++;
      inversions += (j - (mid + 1));
    }
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
        temp.push_back(arr[left++]);
      else
        temp.push_back(arr[right++]);
    }
    while (left <= mid)
      temp.push_back(arr[left++]);
    while (right <= high)
      temp.push_back(arr[right++]);
    for (int k = low; k <= high; k++)
      arr[k] = temp[k - low];
    return inversions;
  };
  return pairs(pairs, 0, arr.size() - 1);
}
int main()
{
  vector<int> arr = {1, 4, 7, 2, 5, 9};
  // time complexity is O(N*Log(N)) and space complexity is O(N)
  cout << reversePair(arr) << "\n";
  return 0;
}
