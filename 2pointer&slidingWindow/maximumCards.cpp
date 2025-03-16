// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &arr, int k)
{
  int n = arr.size(), i = n - k, j = n - k, ans = 0;
  while (i < n)
  {
    ans += arr[i];
    i++;
  }
  i = 0;
  int temp = ans;
  while (i < k)
  {
    temp += arr[i] - arr[j];
    ans = max(ans, temp);
    i++;
    j++;
  }
  return ans;
}
int main()
{
  return 0;
}