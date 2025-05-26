// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int kthSmallest(vector<vector<int>> &mat, int k)
  {
    vector<int> row = mat[0];
    for (int i = 1; i < mat.size(); ++i)
    {
      vector<int> nr;
      for (int j = 0; j < mat[i].size(); ++j)
      {

        for (auto n : row)
        {
          nr.push_back(mat[i][j] + n);
        }
      }
      sort(nr.begin(), nr.end());
      row.resize(min(k, int(nr.size())));
      for (int x = 0; x < min(k, int(nr.size())); ++x)
      {
        row[x] = nr[x];
      }
    }
    return row[k - 1];
  }
};
class Solution
{
public:
  int kthSmallest(vector<vector<int>> &mat, int k)
  {
    int m = mat.size(), n = mat[0].size();
    int left = m, right = m * 5000, ans = -1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      int cnt = countArraysHaveSumLessOrEqual(mat, m, n, mid, 0, 0, k);
      if (cnt >= k)
      {
        ans = mid;
        right = mid - 1;
      }
      else
        left = mid + 1;
    }
    return ans;
  }
  int countArraysHaveSumLessOrEqual(vector<vector<int>> &mat, int m, int n, int targetSum, int r, int sum, int k)
  {
    if (sum > targetSum)
      return 0;
    if (r == m)
      return 1;
    int ans = 0;
    for (int c = 0; c < n; ++c)
    {
      int cnt = countArraysHaveSumLessOrEqual(mat, m, n, targetSum, r + 1, sum + mat[r][c], k - ans);
      if (cnt == 0)
        break;
      ans += cnt;
      if (ans > k)
        break;
    }
    return ans;
  }
};
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &mat, int k)
  {
    int m = mat.size(), n = mat[0].size();
    if (m == 1)
      return mat[0][k - 1];

    vector<int> ans = kSmallestSumPairs(mat[0], mat[1], k);
    for (int r = 2; r < m; ++r)
    {
      ans = kSmallestSumPairs(ans, mat[r], k);
    }
    return ans[k - 1];
  }

private:
  vector<int> kSmallestSumPairs(const vector<int> &arr1, const vector<int> &arr2, int k)
  {
    using T = tuple<int, int, int>; // (sum, index in arr1, index in arr2)
    priority_queue<T, vector<T>, greater<T>> minHeap;

    int len1 = arr1.size(), len2 = arr2.size();
    for (int i = 0; i < min(len1, k); ++i)
    {
      minHeap.emplace(arr1[i] + arr2[0], i, 0);
    }

    vector<int> ans;
    while (k-- > 0 && !minHeap.empty())
    {
      auto [sum, i, j] = minHeap.top();
      minHeap.pop();
      ans.push_back(sum);
      if (j + 1 < len2)
      {
        minHeap.emplace(arr1[i] + arr2[j + 1], i, j + 1);
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}