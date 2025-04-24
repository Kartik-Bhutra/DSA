// https://leetcode.com/problems/symmetric-tree/description/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  bool checksym(TreeNode* le, TreeNode* ri) {
    if (le == nullptr || ri == nullptr) return le == ri;
    if (le->val != ri->val) return false;
    return (checksym(le->left, ri->right) && checksym(le->right, ri->left));
  }
  bool isSymmetric(TreeNode* root) {
    return checksym(root->left, root->right);
  }
};
int main() {

  return 0;
}