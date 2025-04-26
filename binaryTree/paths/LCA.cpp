// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
      return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
  }
};
class Solution {
public:
  bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
    if (root == nullptr) return false;
    path.push_back(root);

    if (root == target) return true;

    if (findPath(root->left, target, path) || findPath(root->right, target, path))
      return true;

    path.pop_back();
    return false;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathToP, pathToQ;

    if (!findPath(root, p, pathToP) || !findPath(root, q, pathToQ))
      return nullptr;
    int i = 0;
    while (i < pathToP.size() && i < pathToQ.size() && pathToP[i] == pathToQ[i]) {
      i++;
    }

    return pathToP[i - 1];
  }
};
int main() {

  return 0;
}