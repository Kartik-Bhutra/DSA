#include <bits/stdc++.h>
using namespace std;
vector<int> secondGreaterElement(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ng(n, n), ns(n, n);
  stack<int> s;
  for (int i = n - 1; i >= 0; i--)
  {
    while (!s.empty() && arr[s.top()] <= arr[i])
      s.pop();
    if (!s.empty())
      ng[i] = s.top();
    s.push(i);
  }
  while (!s.empty())
    s.pop();
  for (int i = n - 1; i >= 0; i--)
  {
    while (!s.empty() && arr[s.top()] > arr[i])
      s.pop();
    if (!s.empty())
      ns[i] = s.top();
    s.push(i);
  }
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++)
  {
    int g = ng[i];
    if (g < n - 1)
    {
      int ngs = ns[g], nng = ng[g];
      if (nng == n)
      {
        int x = ngs;
        while (x < n && arr[x] <= arr[i])
          x = ng[x];
        if (x < n)
        {
          ans[i] = arr[x];
        }
      }
      else
      {
        if (ngs < nng)
        {
          int x = ngs;
          while (x < nng && arr[x] <= arr[i])
            x = ng[x];
          if (x < nng)
          {
            ans[i] = arr[x];
          }
          else
          {
            ans[i] = arr[nng];
          }
        }
        else
        {
          ans[i] = arr[nng];
        }
      }
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {2, 4, 0, 9, 6};
  return 0;
}