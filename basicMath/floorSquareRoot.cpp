// https://www.geeksforgeeks.org/problems/square-root/0
#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int num)
{
  if (num <= 3)
    return 1;
  int low = 2, high = num / 2;
  while (high >= low)
  {
    int mid = low + (high - low) / 2;
    int square = mid * mid;
    if (square == num)
      return mid;
    else if (square > num)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return high;
}
int main()
{
  int num = 10;
  cout << floorSqrt(num) << "\n";
  return 0;
}