// https://www.naukri.com/code360/problems/boundary-traversal_790725
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
void traverseleft(TreeNode* root, vector<int>& ans) {
  if (root == NULL || root->left == NULL && root->right == NULL) {
    return;
  }
  ans.push_back(root->val);
  if (root->left) {
    traverseleft(root->left, ans);
  }
  else {
    traverseleft(root->right, ans);
  }
}
void traversalEaf(TreeNode* root, vector<int>& ans) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    ans.push_back(root->val);
    return;
  }
  traversalEaf(root->left, ans);
  traversalEaf(root->right, ans);
}
void  traverseright(TreeNode* root, vector<int>& ans) {
  if (root == NULL || root->left == NULL && root->right == NULL) {
    return;
  }
  if (root->right) {
    traverseright(root->right, ans);
  }
  else {
    traverseright(root->left, ans);
  }
  ans.push_back(root->val);
}
vector<int> traverseBoundary(TreeNode* root)
{
  vector<int> ans;
  if (root == NULL) {
    return ans;
  }
  ans.push_back(root->val);
  traverseleft(root->left, ans);
  traversalEaf(root->left, ans);
  traversalEaf(root->right, ans);
  traverseright(root->right, ans);
}
int main() {
  return 0;
}