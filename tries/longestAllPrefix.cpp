// https://leetcode.com/problems/longest-word-with-all-prefixes/description/
#include <bits/stdc++.h>
using namespace std;
class Trie
{
  Trie *children[26];
  bool isWord;

public:
  Trie()
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = nullptr;
    }
    isWord = false;
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
    node->isWord = true;
  }
  bool allPrefixes(string word)
  {
    Trie *node = this;
    for (char ch : word)
    {
      int index = ch - 'a';
      node = node->children[index];
      if (node->isWord == false)
      {
        return false;
      }
    }
    return true;
  }
};
string longestValidWord(vector<string> &words)
{
  Trie t;
  for (string &s : words)
  {
    t.insert(s);
  }
  string ans = "";
  for (string &s : words)
  {
    if ((s.size() > ans.size() && t.allPrefixes(s)) || (s.size() == ans.size() && s < ans && t.allPrefixes(s)))
    {
      ans = s;
    }
  }
}
int main()
{
  return 0;
}