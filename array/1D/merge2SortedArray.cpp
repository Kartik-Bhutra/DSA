#include <bits/stdc++.h>
using namespace std;
void mergeSortedArray(vector<int> &vec1, vector<int> &vec2)
{
  int m = vec1.size() - 1, n = vec2.size() - 1;
  m -= n + 1;
  while (m >= 0 && n >= 0)
  {
    // normally adding to the last
    if (vec1[m] >= vec2[n])
    {
      vec1[m + n + 1] = vec1[m];
      m--;
    }
    else
    {
      vec1[m + n + 1] = vec2[n];
      n--;
    }
  }
  while (n >= 0)
  {
    vec1[m + n + 1] = vec2[n];
    n--;
  }
}
int main()
{
  vector<int> vec1 = {1, 2, 3, 0, 0, 0}, vec2 = {2, 3, 4};
  // time complexity O(N) and space complexity O(1)
  mergeSortedArray(vec1, vec2);
  [&vec1]()
  {
    for (int x : vec1)
    {
      cout << x << " ";
    }
    cout << "\n";
  }();
  return 0;
}