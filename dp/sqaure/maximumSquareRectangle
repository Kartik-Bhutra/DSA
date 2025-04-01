// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
#include <bits/stdc++.h>
using namespace std;
int countSquares(vector<vector<int>> &matrix)
{
  int n = matrix.size(), m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = matrix[i][0];
    ans += dp[i][0];
  }
  for (int j = 1; j < m; j++)
  {
    dp[0][j] = matrix[0][j];
    ans += dp[0][j];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (matrix[i][j] == 1)
      {
        dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
      }
      ans += dp[i][j];
    }
  }
  return ans;
}
int countSquares(vector<vector<int>> &nums)
{
  int ans = 0, n = nums.size(), m = nums[0].size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      ans += nums[i][j];
    }
  }
  int k = 1;
  while (++k)
  {
    if (n >= k && m >= k)
    {
      for (int i = 0; i <= n - k; i++)
      {
        for (int j = 0; j <= m - k; j++)
        {
          if (nums[i][j] && nums[i + 1][j] && nums[i][j + 1] && nums[i + 1][j + 1])
          {
            ans++;
            nums[i][j] = 1;
          }
          else
          {
            nums[i][j] = 0;
          }
        }
      }
    }
    else
    {
      return ans;
    }
  }
  return ans;
}
int main()
{
  return 0;
}