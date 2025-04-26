// https://leetcode.com/problems/count-complete-tree-nodes/description/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
  int findHeightLeft(TreeNode* node) {
    int height = 0;
    while (node) {
      height++;
      node = node->left;
    }
    return height;
  }
  int findHeightRight(TreeNode* node) {
    int height = 0;
    while (node) {
      height++;
      node = node->right;
    }
    return height;
  }
public:
  int countNodes(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if (lh == rh) {
      return (1 << lh) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
int main() {
  return 0;
}