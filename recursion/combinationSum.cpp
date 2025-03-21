#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> combinationSum(vector<int> &c, int k)
{
  vector<vector<int>> a;
  function<void(int, int, vector<int> &)> r = [&](int i, int s, vector<int> &v)
  {
    if (s == 0)
    {
      a.push_back(v);
      return;
    }
    if (i < 0)
      return;
    while (s >= 0)
    {
      r(i - 1, s, v);
      v.push_back(c[i]);
      s -= c[i];
    }
    while (!v.empty() && v.back() == c[i])
    {
      s += c[i];
      v.pop_back();
    }
  };
  vector<int> v;
  r(c.size() - 1, k, v);
  return a;
}
int main()
{
  vector<int> c = {2, 3, 6, 7};
  int k = 7;
  vector<vector<int>> result = combinationSum(c, k);
  for (const auto &comb : result)
  {
    for (int num : comb)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}