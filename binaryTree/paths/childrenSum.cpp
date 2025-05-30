// https://www.naukri.com/code360/problems/childrensumproperty_790723
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
void changeTree(TreeNode* root) {
  if (root == NULL) {
    return;
  }
  int child = 0;
  if (root->left) {
    child += root->left->val;
  }
  if (root->right) {
    child += root->right->val;
  }
  if (child >= root->val) {
    root->val = child;
  }
  else {
    if (root->left) {
      root->left->val = root->val;
    }
    else if (root->right) {
      root->right->val = root->val;
    }
  }
  changeTree(root->left);
  changeTree(root->right);
  int tot = 0;
  if (root->left) {
    tot += root->left->val;
  }
  if (root->right) {
    tot += root->right->val;
  }
  if (root->left or root->right) {
    root->val = tot;
  }
}
int main() {
  return 0;
}