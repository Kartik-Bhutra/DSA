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
        if (node->bit[b])
        {
          node = node->bit[b];
        }
        else
        {
          return -1;
        }
      }
    }
    return maxXor;
  }
};

class Solution
{
public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
  {
    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
      queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });
    vector<int> ans(q);
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int j = 0;
    Trie t;
    for (int i = 0; i < q; i++)
    {
      while (j < n && nums[j] <= queries[i][1])
      {
        t.insert(nums[j]);
        j++;
      }
      ans[queries[i][2]] = (j == 0 ? -1 : t.getMaxXor(queries[i][0]));
    }
    return ans;
  }
};

class Solution
{
public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
  {
    const int n = nums.size(), q = queries.size();
    vector<int> ans(q, -1);
    sort(nums.begin(), nums.end());

    for (int i = 0; i < q; i++)
    {
      const int x = queries[i][0], m = queries[i][1];
      if (m < nums[0])
        continue;

      int end = upper_bound(nums.begin(), nums.end(), m) - nums.begin();
      int start = 0;

      int k = 0, cur = 0;
      for (int bit = 31; bit >= 0; bit--)
      {
        if (x & (1 << bit))
        { // hope A[i] this bit == 0
          if (!(nums[start] & (1 << bit)))
          {
            k |= 1 << bit;
            end = lower_bound(nums.begin() + start, nums.begin() + end, cur | (1 << bit)) - nums.begin();
          }
          else
          {
            cur |= 1 << bit;
          }
        }
        else
        { // hope: A[i] this bit == 1
          if (start <= end - 1 && (nums[end - 1] & (1 << bit)))
          {
            k |= 1 << bit;
            cur |= 1 << bit;
            start = lower_bound(nums.begin() + start, nums.begin() + end, cur) - nums.begin();
          }
        }
      }
      ans[i] = k;
    }
    return ans;
  }
};

int main()
{
  return 0;
}