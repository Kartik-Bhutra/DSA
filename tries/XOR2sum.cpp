// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
#include <bits/stdc++.h>
using namespace std;
class Trie
{
public:
  Trie *bit[2];
  Trie()
  {
    bit[0] = nullptr;
    bit[1] = nullptr;
  }
  void insert(int num)
  {
    Trie *node = this;
    for (int i = 31; i >= 0; i--)
    {
      int b = (num >> i) & 1;
      if (!node->bit[b])
      {
        node->bit[b] = new Trie();
      }
      node = node->bit[b];
    }
  }
  int getMaxXor(int num)
  {
    Trie *node = this;
    int maxXor = 0;
    for (int i = 31; i >= 0; i--)
    {
      int b = (num >> i) & 1;
      if (node->bit[1 - b])
      {
        maxXor |= (1 << i);
        node = node->bit[1 - b];
      }
      else
      {
        node = node->bit[b];
      }
    }
    return maxXor;
  }
};
class Solution
{
public:
  int findMaximumXOR(vector<int> &nums)
  {
    Trie t;
    for (int x : nums)
      t.insert(x);
    int maxXor = 0;
    for (int x : nums)
    {
      maxXor = max(maxXor, t.getMaxXor(x));
    }
    return maxXor;
  }
};
int main()
{
  return 0;
}