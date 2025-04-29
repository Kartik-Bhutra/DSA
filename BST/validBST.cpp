// https://leetcode.com/problems/validate-binary-search-tree/description/
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
  bool check(TreeNode* root, long long l, long long r) {
    if (!root) return true;
    if (root->val <= l || root->val >= r) return false;
    return check(root->left, l, root->val) && check(root->right, root->val, r);
  }
public:
  bool isValidBST(TreeNode* root) {
    return check(root, LLONG_MIN, LLONG_MAX);
  }
};
class Solution {
public:
  TreeNode* prev = nullptr;
  bool solve(TreeNode* root) {
    if (root == nullptr)
      return true;
    if (solve(root->left) == NULL) {
      return false;
    }
    if (prev && root->val <= prev->val) {
      return false;
    }
    prev = root;
    return solve(root->right);
  }
  bool isValidBST(TreeNode* root) {
    return solve(root);
  }
};
int main() {
  return 0;
}