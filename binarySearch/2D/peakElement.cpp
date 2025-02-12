// https://leetcode.com/problems/find-a-peak-element-ii/
#include <bits/stdc++.h>
using namespace std;
vector<int> peakElement(vector<vector<int>> &mat)
{
  int low = 0, high = mat[0].size() - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int maxRow = 0;
    for (int i = 0; i < mat.size(); i++)
    {
      if (mat[i][mid] > mat[maxRow][mid])
      {
        maxRow = i;
      }
    }
    bool leftIsSmaller = (mid == 0) || (mat[maxRow][mid] > mat[maxRow][mid - 1]);
    bool rightIsSmaller = (mid == mat[0].size() - 1) || (mat[maxRow][mid] > mat[maxRow][mid + 1]);
    if (leftIsSmaller && rightIsSmaller)
    {
      return {maxRow, mid};
    }
    else if (!leftIsSmaller)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return {-1, -1};
}
int main()
{
  vector<vector<int>> mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
  // time complexity is O(N*Log(M)) and space complexity is O(1)
  vector<int> peak = peakElement(mat);
  cout << peak[0] << " " << peak[1] << "\n";
  return 0;
}