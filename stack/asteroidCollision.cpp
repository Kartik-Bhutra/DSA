// https://leetcode.com/problems/asteroid-collision/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (ans.empty())
      ans.push_back(arr[i]);
    else
    {
      if (arr[i] < 0)
      {
        while (!ans.empty() && ans.back() > 0 && ans.back() < -arr[i])
          ans.pop_back();
        if (!ans.empty() && ans.back() > -arr[i])
          continue;
        else if (!ans.empty() && ans.back() == -arr[i])
        {
          ans.pop_back();
          continue;
        }
        else
          ans.push_back(arr[i]);
      }
      else
        ans.push_back(arr[i]);
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {5, 10, -5};
  return 0;
}