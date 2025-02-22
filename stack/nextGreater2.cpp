// https://leetcode.com/problems/next-greater-element-ii/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> &arr)
{
  int n = arr.size() - 1;
  stack<int> st;
  for (int i = n; i >= 0; i--)
  {
    while (st.size() && st.top() <= arr[i])
      st.pop();
    st.push(arr[i]);
  }
  vector<int> ans(n + 1, -1);
  for (int i = n; i >= 0; i--)
  {
    while (st.size() && st.top() <= arr[i])
      st.pop();
    if (st.size())
      ans[i] = st.top();
    st.push(arr[i]);
  }
  return ans;
}
int main()
{
  vector<int> arr = {1, 2, 1};
  vector<int> ans = nextGreater(arr);
  for (int x : ans)
  {
    cout << x << " ";
  }
  return 0;
}