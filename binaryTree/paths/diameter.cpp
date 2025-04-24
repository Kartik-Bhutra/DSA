// 
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree node;
using namespace std;
class Solution {
public:
  int maxDiameter = 0;

  int dfs(TreeNode* root) {
    if (!root) return 0;

    int leftHeight = dfs(root->left);
    int rightHeight = dfs(root->right);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return maxDiameter;
  }
};
int height(node* root, int k, int& ans) {
  if (root == nullptr) return k - 1;
  int l = height(root->left, k + 1, ans);
  int r = height(root->right, k + 1, ans);
  ans = max(l + r - k - k, ans);
  return max(l, r);
}
int diameterOfBinaryTree(TreeNode* root) {
  int ans = 0;
  height(root, 0, ans);
  return ans;
}
int main() {

  return 0;
}