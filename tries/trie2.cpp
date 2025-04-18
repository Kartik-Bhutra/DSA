// https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
class Trie
{
  Trie *children[26];
  int isWord;
  int isPrefix;

public:
  Trie()
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isWord = 0;
    isPrefix = 0;
  }
  void insert(string &word)
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
      node->isPrefix++;
    }
    node->isWord++;
  }
  int countWordsEqualTo(string &word)
  {
    Trie *node = this;
    for (char ch : word)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        return 0;
      }
      node = node->children[index];
    }
    return node->isWord;
  }
  int countWordsStartingWith(string &word)
  {
    Trie *node = this;
    for (char ch : word)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        return 0;
      }
      node = node->children[index];
    }
    return node->isPrefix;
  }
  void erase(string &word)
  {
    Trie *node = this;
    stack<pair<Trie *, int>> st;
    for (char ch : word)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        return;
      }
      st.push({node, index});
      node = node->children[index];
    }
    if (node->isWord == 0)
    {
      return;
    }
    node->isWord--;
    while (!st.empty())
    {
      auto [parent, index] = st.top();
      st.pop();
      parent->children[index]->isPrefix--;
      if (parent->children[index]->isPrefix == 0 &&
          parent->children[index]->isWord == 0)
      {
        delete parent->children[index];
        parent->children[index] = nullptr;
      }
    }
  }
  ~Trie()
  {
    for (int i = 0; i < 26; i++)
    {
      if (children[i])
      {
        delete children[i];
        children[i] = nullptr;
      }
    }
  }
};
class TrieNode
{
public:
  TrieNode *links[26];
  int wordsEndingHere = 0;
  int wordsStartingHere = 0;
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode();
  }

  void insert(string word)
  {
    TrieNode *node = root;
    for (char &w : word)
    {
      int charIndex = w - 'a';
      if (!node->links[charIndex])
      {
        node->links[charIndex] = new TrieNode();
      }
      node = node->links[charIndex];
      node->wordsStartingHere++;
    }
    node->wordsEndingHere++;
  }

  int countWordsEqualTo(string word)
  {
    TrieNode *node = root;
    for (char &w : word)
    {
      int charIndex = w - 'a';
      if (!node->links[charIndex])
      {
        return 0;
      }
      node = node->links[charIndex];
    }
    return node->wordsEndingHere;
  }

  int countWordsStartingWith(string prefix)
  {
    TrieNode *node = root;
    for (char &w : prefix)
    {
      int charIndex = w - 'a';
      if (!node->links[charIndex])
      {
        return 0;
      }
      node = node->links[charIndex];
    }
    return node->wordsStartingHere;
  }

  void erase(string word)
  {
    TrieNode *node = root;
    for (char &w : word)
    {
      int charIndex = w - 'a';
      node = node->links[charIndex];
      node->wordsStartingHere--;
    }
    node->wordsEndingHere--;
  }
};
int main()
{
  return 0;
}