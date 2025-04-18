#ifndef TRIE_HPP
#define TRIE_HPP
#include <iostream>
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
  bool search(string word)
  {
    Trie *node = this;
    for (char ch : word)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        return false;
      }
      node = node->children[index];
    }
    return node->isWord;
  }
  bool startsWith(string prefix)
  {
    Trie *node = this;
    for (char ch : prefix)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        return false;
      }
      node = node->children[index];
    }
    return true;
  }
};
#endif
