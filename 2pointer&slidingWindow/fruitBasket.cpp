// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
#include <bits/stdc++.h>
using namespace std;
int totalFruits(vector<int> &arr)
{
  int f1 = arr[0];
  int i = 1, n = arr.size();
  while (i < n && arr[i] == arr[i - 1])
  {
    i++;
  }
  int total = i;
  if (i < n)
  {
    int f2 = arr[i];
    int j = -1;
    total++;
    i++;
    while (i < n)
    {
      if (arr[i] == f1)
        total = max(total, i - j);
      else if (arr[i] == f2)
        total = max(total, i - j);
      else
      {
        if (arr[i - 1] == f1)
          f2 = arr[i];
        else
          f1 = arr[i];
        j = i - 2;
        while (j > -1 && arr[j] == arr[j + 1])
        {
          j--;
        }
      }
      i++;
    }
  }
  return total;
}
int main()
{

  return 0;
}