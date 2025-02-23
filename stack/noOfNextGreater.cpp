// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaters(vector<int> &arr)
{
  int n = arr.size();
  stack<int> asc, dsc;
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--)
  {
    while (asc.size() && asc.top() <= arr[i])
    {
      dsc.push(asc.top());
      asc.pop();
    }
    ans[i] = asc.size();
    asc.push(arr[i]);
    while (dsc.size())
    {
      asc.push(dsc.top());
      dsc.pop();
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
  // time complexity O(N) and space complexity O(N)
  vector<int> ans = nextGreaters(arr);
  for (int x : ans)
  {
    cout << x << " ";
  }
  return 0;
}