// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int> &v, vector<int> &w, int c)
{
  int n = v.size();
  vector<pair<double, int>> r(n);
  for (int i = 0; i < n; i++)
  {
    r[i] = {(double)v[i] / w[i], w[i]};
  }
  sort(r.begin(), r.end(), [](const pair<double, int> &a, const pair<double, int> &b)
       { return a.first > b.first; });

  double ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (c >= r[i].second)
    {
      c -= r[i].second;
      ans += r[i].first * r[i].second;
    }
    else
    {
      ans += r[i].first * c;
      break;
    }
  }
  return ans;
}

int main()
{
  vector<int> v = {60, 100, 120};
  vector<int> w = {10, 20, 30};
  int c = 50;
  cout << fractionalKnapsack(v, w, c) << endl;
  return 0;
}