#include<bits/stdc++.h>
#include "tree.hpp"
using namespace std;
void postOrder(Tree *root, vector<int> path)
{
  if (root == nullptr)
    return;
  postOrder(root->left, path);
  postOrder(root->right, path);
  path.push_back(root->val);
}
vector<int> postorder(Tree *root)
{
  vector<int> path;
  if (root == NULL)
  {
    return path;
  }
  stack<Tree *> st1, st2;
  st1.push(root);
  while (!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if (root->left != NULL)
    {
      st1.push(root->left);
    }
    if (root->right != NULL)
    {
      st1.push(root->right);
    }
  }
  while (!st2.empty())
  {
    path.push_back(st2.top()->val);
    st2.pop();
  }
  return path;
}
vector<int> postOrderT(Tree *root)
{
  vector<int> path;
  stack<Tree *> st;
  Tree *curr = root;
  while (curr || !st.empty())
  {
    while (curr)
    {
      st.push(curr);
      curr = curr->left;
    }
    Tree *temp = st.top()->right;
    if (temp != NULL)
      curr = temp;
    else
    {
      temp = st.top();
      path.push_back(temp->val);
      st.pop();
      while (!st.empty() && st.top()->right == temp)
      {
        temp = st.top();
        path.push_back(st.top()->val);
        st.pop();
      }
    }
  }
  return path;
}
int main(){
  
  return 0;
}