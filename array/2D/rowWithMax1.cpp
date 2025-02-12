// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/0
#include <bits/stdc++.h>
using namespace std;
int rowWithMax1(vector<vector<bool>> &mat)
{
  int n = mat.size(), m = mat[0].size();
  int i = 0, j = m - 1, maxIndex = -1;
  while (i < n && j >= 0)
  {
    if (mat[i][j])
    {
      j--;
      maxIndex = i;
    }
    else
      i++;
  }
  return maxIndex;
}
int main()
{
  vector<vector<bool>> mat = {{0, 1, 1, 1},
                              {0, 0, 1, 1},
                              {1, 1, 1, 1},
                              {0, 0, 0, 0}};
  // time complexity is (N+M) and space complexity is O(1)
  cout << rowWithMax1(mat) << "\n";
  return 0;
}