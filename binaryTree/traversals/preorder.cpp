#include<bits/stdc++.h>
#include "tree.hpp"
using namespace std;
void preOrder(Tree *root, vector<int> &path)
{
  if (root == nullptr)
    return;
  path.push_back(root->val);
  preOrder(root->left, path);
  preOrder(root->right, path);
}
vector<int> preorder(Tree *root)
{
  if (root == nullptr)
    return {};
  vector<int> path;
  stack<Tree *> st;
  st.push(root);
  while (st.size())
  {
    Tree *node = st.top();
    st.pop();
    path.push_back(node->val);
    if (node->right)
      st.push(node->right);
    if (node->left)
      st.push(node->left);
  }
  return path;
}
int main(){
  
  return 0;
}