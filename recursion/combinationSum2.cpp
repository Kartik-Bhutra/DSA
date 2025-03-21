#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> combinationSum2(vector<int> &c, int k)
{
  sort(c.begin(), c.end(), greater<int>());
  vector<vector<int>> a;
  function<void(int, int, vector<int>&)> r = [&](int i, int s, vector<int> &v)
  {
    if (s == 0)
    {
      a.push_back(v);
      return;
    }
    if (i < 0)
    {
      return;
    }
    for (int j = i; j >= 0; j--)
    {
      if (j < i && c[j] == c[j + 1])
        continue;
      if (c[j] > s)
        return;
      v.push_back(c[j]);
      r(j - 1, s - c[j], v);
      v.pop_back();
    }
  };
  vector<int> v;
  r(c.size() - 1, k, v);
  return a;
}
int main()
{
  vector<int> c = {10, 1, 2, 7, 6, 1, 5};
  int k = 8;
  vector<vector<int>> result = combinationSum2(c, k);
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