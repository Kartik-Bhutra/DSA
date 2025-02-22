// https://leetcode.com/problems/min-stack/description/
#include <bits/stdc++.h>
using namespace std;
class minStack
{
private:
  stack<long long> minSt;
  int mini = INT_MAX;

public:
  void push(int val)
  {
    if (minSt.empty())
    {
      mini = val;
      minSt.push(val);
    }
    else
    {
      if (val < mini)
      {
        minSt.push((val - mini) + val);
        mini = val;
      }
      else
        minSt.push(val);
    }
  }
  int top()
  {
    if (minSt.empty())
      return INT_MAX;
    if (minSt.top() < mini)
      return mini;
    return minSt.top();
  }
  void pop()
  {
    if (minSt.empty())
      return;
    if (minSt.top() < mini)
    {
      mini = 2 * mini - minSt.top();
    }
    minSt.pop();
  }
  int getMin()
  {
    return mini;
  }
};
int main()
{
  return 0;
}