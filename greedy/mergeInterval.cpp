// https://leetcode.com/problems/insert-interval/description/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &t)
{
  int n = t.size();
  sort(t.begin(), t.end());
  vector<vector<int>> ans = {{t[0][0], t[0][1]}};
  for (int i = 1; i < n; i++)
  {
    if (t[i][0] <= ans.back()[1])
    {
      ans.back()[1] = max(t[i][1], ans.back()[1]);
    }
    else
    {
      ans.push_back(t[i]);
    }
  }
  return ans;
}
int main()
{

  return 0;
}