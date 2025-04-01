#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LIS_Sort(vector<int> &a)
{
  int n = a.size();
  vector<vector<int>> c;

  for (int i = 0; i < n; i++)
  {
    int j = lower_bound(c.begin(), c.end(), a[i], [](const vector<int> &s, int val)
                        { return s.back() < val; }) -
            c.begin();

    if (j == c.size())
    {
      c.push_back({a[i]});
    }
    else
    {
      if (c[j].back() == a[i])
      {
        c.push_back({a[i]});
      }
      else
      {
        c[j].push_back(a[i]);
      }
    }
  }

  vector<int> ans;
  for (const vector<int> &s : c)
  {
    for (int i = s.size() - 1; i >= 0; i--)
    {
      ans.push_back(s[i]);
    }
  }

  return ans;
}

int main()
{
  vector<int> a = {10, 9, 2, 5, 3,5, 7, 101, 18};
  vector<int> sorted = LIS_Sort(a);

  cout << endl
       << "Sorted array as per LIS logic: ";
  for (int x : sorted)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
