// https://leetcode.com/problems/find-median-from-data-stream/
#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
  priority_queue<int> maxi;
  priority_queue<int, vector<int>, greater<int>> mini;
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    maxi.push(num);
    mini.push(maxi.top());
    maxi.pop();
    if (maxi.size() < mini.size())
    {
      maxi.push(mini.top());
      mini.pop();
    }
  }

  double findMedian()
  {
    if (maxi.size() > mini.size())
      return maxi.top();
    return (maxi.top() + mini.top()) / 2.0;
  }
};
int main()
{

  return 0;
}