// https://leetcode.com/problems/search-a-2d-matrix/description/
#include <bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>> &mat, int target)
{
  int n = mat.size(), m = mat[0].size() - 1;
  int i = 0, j = m;
  while (i < n && j >= 0)
  {
    if (mat[i][j] == target)
      return true;
    else if (mat[i][j] > target)
      j--;
    else
      i++;
  }
  return false;
}
int main()
{
  vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  // time complexity is O(N+M) and space complexity is O(1)
  cout << search(mat, 14) << '\n';
  return 0;
}