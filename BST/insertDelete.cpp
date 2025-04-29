// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// https://leetcode.com/problems/delete-node-in-a-bst/description/
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
      return new TreeNode(val);
    }
    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    }
    else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};
class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* parent = nullptr;
    TreeNode* curr = root;
    while (curr && curr->val != key) {
      parent = curr;
      if (key < curr->val) curr = curr->left;
      else curr = curr->right;
    }
    if (!curr) return root;
    if (!curr->left || !curr->right) {
      TreeNode* child = curr->left ? curr->left : curr->right;
      if (!parent) {
        delete curr;
        return child;
      }
      if (parent->left == curr) parent->left = child;
      else parent->right = child;
      delete curr;
    }
    else {
      TreeNode* predParent = curr;
      TreeNode* pred = curr->left;
      while (pred->right) {
        predParent = pred;
        pred = pred->right;
      }
      curr->val = pred->val;
      if (predParent->right == pred) {
        predParent->right = pred->left;
      }
      else {
        predParent->left = pred->left;
      }
      delete pred;
    }
    return root;
  }
};
int main() {
  return 0;
}