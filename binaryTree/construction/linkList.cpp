// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
      if (curr->left) {
        TreeNode* pre = curr->left;
        while (pre->right) {
          pre = pre->right;
        }
        pre->right = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
      }
      curr = curr->right;
    }
  }
};
int main() {
  return 0;
}