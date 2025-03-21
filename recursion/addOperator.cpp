#include <bits/stdc++.h>
using namespace std;
vector<string> addOperators(string n, int k)
{
  vector<string> a;
  function<void(int, long long, long long, string&)> r = [&](int i, long long s, long long p, string &e)
  {
    if (i == n.length())
    {
      if (k == s)
      {
        a.push_back(e);
      }
      return;
    }
    long long t = 0;
    string st = "";
    for (int j = i; j < n.length(); j++)
    {
      if (j > i && n[i] == '0')
        break;
      t = t * 10 + n[j] - '0';
      st += n[j];
      if (i == 0)
      {
        string temp = e;
        e += st;
        r(j + 1, t, t, e);
        e = temp;
      }
      else
      {
        string temp = e;
        e += '+' + st;
        r(j + 1, s + t, t, e);
        e = temp;
        e += '-' + st;
        r(j + 1, s - t, -t, e);
        e = temp;
        e += '*' + st;
        r(j + 1, s - p + p * t, p * t, e);
        e = temp;
      }
    }
  };
  string e = "";
  r(0, 0, 0, e);
  return a;
}
int main()
{
  string n = "105";
  int k = 5;
  vector<string> result = addOperators(n, k);
  for (const auto &expr : result)
  {
    cout << expr << endl;
  }
  return 0;
}