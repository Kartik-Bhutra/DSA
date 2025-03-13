// https://leetcode.com/problems/jump-game-ii/description/
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &arr)
{
  int ans = 0, c = 0, f = 0;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    f = max(f, i + arr[i]);
    if (i == c)
    {
      ans++;
      c = f;
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
  cout << jump(arr);
  return 0;
}