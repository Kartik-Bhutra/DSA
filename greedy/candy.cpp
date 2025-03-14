// https://leetcode.com/problems/candy/description/
#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &r)
{
  int n = r.size();
  int ans = 0, last = -1;
  for (int i = 0; i < n; i++)
  {
    if (i < n - 1 && r[i] <= r[i + 1])
    {
      ans += ((i - last) * (i - last + 1)) / 2;
      last = i;
    }
  }
  for(int i = 0; i < n; i++){
    if(i < n-1 && r[i] < r[i+1])  ans++;
  }
  return ans;
}
int main()
{

  return 0;
}