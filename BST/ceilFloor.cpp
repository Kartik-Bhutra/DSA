#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
int findCeil(TreeNode* root, int key) {
  int ceil = -1;
  while (root) {
    if (root->val == key) {
      ceil = root->val;
      return ceil;
    }
    if (key > root->val) {
      root = root->right;
    }
    else {
      ceil = root->val;
      root = root->left;
    }
  }
  return ceil;
}
int floorInBST(TreeNode* root, int key) {
  int floor = -1;
  while (root) {
    if (root->val == key) {
      floor = root->val;
      return floor;
    }
    if (key > root->val) {
      floor = root->val;
      root = root->right;
    }
    else {
      root = root->left;
    }
  }
  return floor;
}
int main() {
  return 0;
}