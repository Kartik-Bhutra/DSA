// https://leetcode.com/problems/next-greater-element-i/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> &arr1, vector<int> &arr2)
{
  int n = arr1.size(), m = arr2.size() - 1;
  vector<int> st = {-1};
  unordered_map<int, int> mp;
  for (int i = m; i >= 0; i--)
  {
    while (st.back() != -1 && arr2[i] > st.back())
      st.pop_back();
    mp[arr2[i]] = st.back();
    st.push_back(arr2[i]);
  }
  vector<int> ng;
  for (int i = 0; i < n; i++)
  {
    ng.push_back(mp[arr1[i]]);
  }
  return ng;
}
int main()
{
  vector<int> arr1 = {4, 1, 2}, arr2 = {1, 3, 4, 2};
  // time complexity O(N) and space complexity O(N)
  vector<int> ans = nextGreater(arr1, arr2);
  int n = arr1.size();
  for (int i = 0; i < n; i++)
  {
    cout << arr1[i] << " " << ans[i] << '\n';
  }
  return 0;
}