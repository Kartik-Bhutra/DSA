// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include <bits/stdc++.h>
using namespace std;
int matrixMultiplication(vector<int> &a)
{
  int N = a.size();
  vector<vector<int>> dp(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++)
  {
    dp[i][i] = 0;
  }
  for (int len = 2; len < N; len++)
  {
    for (int i = 1; i < N - len + 1; i++)
    {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++)
      {
        int cost = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
        dp[i][j] = min(dp[i][j], cost);
      }
    }
  }
  return dp[1][N - 1];
}
int main()
{
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i <= n; i++)
  {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  vector<vector<int>> pat(n + 1, vector<int>(n + 1, -1));
  function<int(int i, int j)> r = [&](int i, int j) -> int
  {
    if (i == j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
      int t = r(i, k) + r(k + 1, j) + a[i - 1] * a[k] * a[j];
      if (t < mini)
      {
        mini = r(i, k) + r(k + 1, j) + a[i - 1] * a[k] * a[j];
        pat[i][j] = k;
      }
    }
    return dp[i][j] = mini;
  };
  cout << r(1, n) << endl;
  function<string(int i, int j)> r2 = [&](int i, int j) -> string
  {
    if (i == j)
    {
      return "T" + to_string(i);
    }
    string s = "(";
    s += r2(i, pat[i][j]);
    s += "*";
    s += r2(pat[i][j] + 1, j);
    return s + ")";
  };
  cout << r2(1, n) << endl;
  return 0;
}