// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
#include <bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int min = INT_MAX, max = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (mat[i][0] < min)
      min = mat[i][0];
    if (mat[i][m - 1] > max)
      max = mat[i][m - 1];
  }
  int desired = (n * m + 1) / 2;
  while (min < max)
  {
    int mid = min + (max - min) / 2;
    int place = 0;
    for (int i = 0; i < n; ++i)
      place +=
          upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
    if (place < desired)
      min = mid + 1;
    else
      max = mid;
  }
  return min;
}
int main()
{
  vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  // time compleity is O(1e5*Log(M)*N) and space is O(1)
  cout << median(mat) << "\n";
  return 0;
}