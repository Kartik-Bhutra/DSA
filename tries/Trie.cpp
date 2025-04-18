// https://leetcode.com/problems/implement-trie-prefix-tree/
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
struct Node
{
  Node *links[26];
  bool flag = false;
  bool containsKey(char ch)
  {
    return links[ch - 'a'] != NULL;
  }
  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }
  Node *get(char ch)
  {
    return links[ch - 'a'];
  }
  void setEnd()
  {
    flag = true;
  }
  bool isEnd()
  {
    return flag;
  }
};
class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }
  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }
  bool search(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return false;
      }
      node = node->get(word[i]);
    }
    return node->isEnd();
  }
  bool startsWith(string prefix)
  {
    Node *node = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      if (!node->containsKey(prefix[i]))
      {
        return false;
      }
      node = node->get(prefix[i]);
    }
    return true;
  }
};
int main()
{
  return 0;
}