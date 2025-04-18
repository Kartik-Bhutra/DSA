#include <bits/stdc++.h>
#include "tree.hpp"
using namespace std;
vector<vector<int>> levelOrder(Tree *head)
{
  if (head == nullptr)
    return {};
  vector<vector<int>> vec;
  queue<Tree *> qe;
  qe.push(head);
  while (qe.size())
  {
    int size = qe.size();
    vector<int> temp;
    while (size--)
    {
      Tree *root = qe.front();
      qe.pop();
      if (root->left)
        qe.push(root->left);
      if (root->right)
        qe.push(root->right);
      temp.push_back(root->val);
    }
    vec.push_back(temp);
  }
  return vec;
}
void levelorder(Tree *node, int level, vector<vector<int>> &result)
{
  if (!node)
  {
    return;
  }

  if (result.size() <= level)
  {
    result.push_back({});
  }

  result[level].push_back(node->val);

  levelorder(node->left, level + 1, result);
  levelorder(node->right, level + 1, result);
}
int main()
{

  return 0;
}