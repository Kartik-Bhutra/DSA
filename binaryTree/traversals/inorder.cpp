#include <bits/stdc++.h>
#include "tree.hpp"
using namespace std;
void inOrder(Tree *root, vector<int> &path)
{
  if (root == nullptr)
    return;
  inOrder(root->left, path);
  path.push_back(root->val);
  inOrder(root->right, path);
}
vector<int> inorder(Tree *root)
{
  if (root == nullptr)
    return {};
  vector<int> path;
  stack<Tree *> st;
  Tree *curr = root;
  while (!st.empty() || curr != nullptr)
  {
    if (curr)
    {
      st.push(curr);
      curr = curr->left;
    }
    else
    {
      curr = st.top();
      st.pop();
      path.push_back(curr->val);
      curr = curr->right;
    }
  }
  return path;
}
int main()
{

  return 0;
}