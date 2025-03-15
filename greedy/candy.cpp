// https://leetcode.com/problems/candy/description/
#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &ratings)
{

  vector<int> left(ratings.size(), 1);

  left[0] = 1;
  for (int i = 1; i < ratings.size(); i++)
  {
    if (ratings[i] > ratings[i - 1])
    {
      left[i] = left[i - 1] + 1;
    }
  }
  int sum = left[ratings.size() - 1];
  int r = 1;

  for (int i = ratings.size() - 2; i >= 0; i--)
  {
    if (ratings[i] > ratings[i + 1])
    {
      r = r + 1;
    }
    else
    {
      r = 1;
    }
    sum += max(r, left[i]);
  }

  return sum;
}
int main()
{

  return 0;
}