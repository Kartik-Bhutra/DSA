// https://leetcode.com/problems/balanced-binary-tree/description/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
using namespace std;
typedef Tree node;
typedef Tree TreeNode;
class Solution {
public:
  int height(node* root, int k, bool& bl) {
    if (root == NULL)    return k - 1;
    if (bl) {
      int lt = height(root->left, k + 1, bl);
      int r = height(root->right, k + 1, bl);
      if (abs(lt - r) <= 1) {
        return max(lt, r);
      }
      else {
        bl = false;
        return 0;
      }
    }
    else {
      return 0;
    }
  }
  bool isBalanced(TreeNode* root) {
    bool bl = true;
    height(root, 0, bl);
    return bl;
  }
};
int main() {

  return 0;
}