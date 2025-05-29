// https://leetcode.com/problems/maximum-frequency-stack/
#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
private:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> group;
  int maxfreq;

public:
  FreqStack()
  {
    maxfreq = 0;
  }

  void push(int val)
  {
    freq[val]++;
    group[freq[val]].push(val);
    maxfreq = max(maxfreq, freq[val]);
  }

  int pop()
  {
    int val = group[maxfreq].top();
    group[maxfreq].pop();
    freq[val]--;

    if (group[maxfreq].empty())
    {
      maxfreq--;
    }

    return val;
  }
};

int main()
{
  FreqStack *freqStack = new FreqStack();
  freqStack->push(5);
  freqStack->push(7);
  freqStack->push(5);
  freqStack->push(7);
  freqStack->push(4);
  freqStack->push(5);

  cout << freqStack->pop() << endl; 
  cout << freqStack->pop() << endl; 
  cout << freqStack->pop() << endl; 
  cout << freqStack->pop() << endl; 

  delete freqStack;
  return 0;
}