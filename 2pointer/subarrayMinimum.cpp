// https://leetcode.com/problems/sum-of-subarray-minimums/
#include <bits/stdc++.h>
using namespace std;
int subarrayMinimum(vector<int> &arr)
{
  int n = arr.size();
  int ans = 0, mod = 1e9 + 7;
  vector<int> left(n), right(n);
  stack<int> min;
  min.push(n);
  for (int i = n - 1; i >= 0; i--)
  {
    while (min.top() != n && arr[min.top()] >= arr[i])
      min.pop();
    right[i] = min.top() - i;
    min.push(i);
  }
  min = stack<int>();
  min.push(-1);
  for (int i = 0; i < n; i++)
  {
    while (min.top() != -1 && arr[min.top()] > arr[i])
      min.pop();
    left[i] = i - min.top();
    min.push(i);
  }
  for (int i = 0; i < n; i++)
    ans = (ans + ((1LL * arr[i]) * left[i] * right[i]) % mod) % mod;
  return ans;
}
int main()
{
  vector<int> arr = {3, 1, 2, 4};
  // time complexity O(N) and space complexity O(N)
  cout << subarrayMinimum(arr) << "\n";
  return 0;
}