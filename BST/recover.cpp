// https://leetcode.com/problems/recover-binary-search-tree/description/
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  TreeNode* first = nullptr, * second = nullptr, * prev = nullptr;
  void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    if (prev && prev->val > root->val) {
      if (first == nullptr) {
        first = prev;
      }
      second = root;
    }
    prev = root;
    inorder(root->right);
  }
  void recoverTree(TreeNode* root) {
    inorder(root);
    if (first && second) {
      swap(first->val, second->val);
    }
  }
};
int main() {
  return 0;
}