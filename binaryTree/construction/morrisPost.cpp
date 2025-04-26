#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
vector<int> postOrder(Node* root) {
  vector<int> ans;
  while (root) {
    if (!root->right) {
      ans.push_back(root->val);
      root = root->left;
    }
    else {
      Node* curr = root->right;
      while (curr->left && curr->left != root)
        curr = curr->left;
      if (curr->left == NULL) {
        ans.push_back(root->val);
        curr->left = root;
        root = root->right;
      }
      else {
        curr->left = NULL;
        root = root->left;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  return 0;
}