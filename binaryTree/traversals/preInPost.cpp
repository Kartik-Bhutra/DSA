#include<bits/stdc++.h>
#include "tree.hpp"
using namespace std;
vector<vector<int>> preInPostTraversal(Tree *root)
{
  vector<int> pre, in, post;
  if (root == NULL)
  {
    return {};
  }
  stack<pair<Tree *, int>> st;
  st.push({root, 1});
  while (!st.empty())
  {
    auto it = st.top();
    st.pop();
    if (it.second == 1)
    {
      pre.push_back(it.first->val);
      it.second = 2;
      st.push(it);
      if (it.first->left != NULL)
      {
        st.push({it.first->left, 1});
      }
    }
    else if (it.second == 2)
    {
      in.push_back(it.first->val);
      it.second = 3;
      st.push(it);
      if (it.first->right != NULL)
      {
        st.push({it.first->right, 1});
      }
    }
    else
    {
      post.push_back(it.first->val);
    }
  }
  vector<vector<int>> result;
  result.push_back(pre);
  result.push_back(in);
  result.push_back(post);
  return result;
}
int main(){
  
  return 0;
}