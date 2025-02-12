// https://leetcode.com/problems/search-a-2d-matrix/description/
#include <bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>> &mat, int target)
{
  int low = 0, high = mat.size() - 1;
  int rowIdx = -1;
  while (high >= low)
  {
    int mid = (high + low) / 2;
    if (mat[mid][0] <= target)
    {
      low = mid + 1;
      rowIdx = mid;
    }
    else
      high = mid - 1;
  }
  if (rowIdx != -1)
  {
    low = 0, high = mat[0].size() - 1;
    while (high >= low)
    {
      int mid = (high + low) / 2;
      if (mat[rowIdx][mid] == target)
        return true;
      else if (mat[rowIdx][mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return false;
  }
  return false;
}
int main()
{
  vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  // time complexity is O(Log(N) + Log(M)) and space complexity is O(1)
  cout << search(mat, 14) << '\n';
  return 0;
}