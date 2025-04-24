// https://www.naukri.com/code360/problems/bottom-view-of-binary-tree_893110
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
void findRange(TreeNode* node, int hd, int& leftMost, int& rightMost) {
  if (node == nullptr)
    return;
  leftMost = min(leftMost, hd);
  rightMost = max(rightMost, hd);
  findRange(node->left, hd - 1, leftMost, rightMost);
  findRange(node->right, hd + 1, leftMost, rightMost);
}
void dfs(TreeNode* node, int hd, int depth, vector<int>& res, vector<int>& levels, int offset) {
  if (node == nullptr)
    return;
  dfs(node->left, hd - 1, depth + 1, res, levels, offset);
  dfs(node->right, hd + 1, depth + 1, res, levels, offset);
  int idx = hd + offset;
  if (levels[idx] <= depth) {
    res[idx] = node->val;
    levels[idx] = depth;
  }
}
vector<int> bottomView(TreeNode* root) {
  if (root == nullptr)
    return {};
  int leftMost = 0, rightMost = 0;
  findRange(root, 0, leftMost, rightMost);
  int width = rightMost - leftMost + 1;
  int offset = -leftMost;
  vector<int> res(width, -1);
  vector<int> levels(width, -1);
  dfs(root, 0, 0, res, levels, offset);
  return res;
}
int main() {
  return 0;
}