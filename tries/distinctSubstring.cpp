// http://naukri.com/code360/problems/count-distinct-substrings_985292
#include <bits/stdc++.h>
using namespace std;
class Trie
{
  Trie *children[26];

public:
  Trie()
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = nullptr;
    }
  }
  void insert(string word)
  {
    Trie *node = this;
    for (char ch : word)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        node->children[index] = new Trie();
      }
      node = node->children[index];
    }
  }
  int countSubstring(Trie *node)
  {
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
      if (node->children[i] != nullptr)
      {
        ans += 1 + countSubstring(node->children[i]);
      }
    }
    return ans;
  }
};
int countDistinctSubstrings(string &s)
{
  Trie t;
  for (int i = 0; i < s.size(); i++)
  {
    string suffix = s.substr(i);
    t.insert(suffix);
  }
  return 1 + t.countSubstring(&t);
}
int main()
{
  return 0;
}