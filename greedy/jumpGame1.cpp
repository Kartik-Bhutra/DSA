// https://leetcode.com/problems/jump-game/description/
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &arr)
{
  int n = arr.size();
  bool c = 1;
  int last = n - 1;
  for (int i = n - 2; i >= 0; i--)
  {
    if (c)
    {
      if (arr[i] < 1)
        c = 0;
      else
        last = i;
    }
    else
    {
      if (arr[i] >= last - i)
      {
        c = 1;
        last = i;
      }
    }
    cout << c << endl;
  }
  return c;
}
int main()
{
  vector<int> arr = {1, 1, 2, 2, 0, 1, 1};
  canJump(arr);
  return 0;
}