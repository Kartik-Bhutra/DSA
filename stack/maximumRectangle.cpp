// https://leetcode.com/problems/largest-rectangle-in-arrgram/
#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &arr)
{
  stack<int> st;
  int maxA = 0;
  int n = arr.size();
  for (int i = 0; i <= n; i++)
  {
    while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
    {
      int height = arr[st.top()];
      st.pop();
      int width;
      if (st.empty())
        width = i;
      else
        width = i - st.top() - 1;
      maxA = max(maxA, width * height);
    }
    st.push(i);
  }
  return maxA;
}
int main()
{

  return 0;
}