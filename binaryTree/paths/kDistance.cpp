// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* curr = q.front(); q.pop();
      if (curr->left) {
        parents[curr->left] = curr;
        q.push(curr->left);
      }
      if (curr->right) {
        parents[curr->right] = curr;
        q.push(curr->right);
      }
    }
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parents;
    markParents(root, parents);

    unordered_map<TreeNode*, bool> vis;
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = true;

    int dist = 0;
    while (!q.empty()) {
      if (dist == k) break;
      int size = q.size();
      dist++;
      for (int i = 0; i < size; ++i) {
        TreeNode* curr = q.front(); q.pop();
        if (curr->left && !vis[curr->left]) {
          vis[curr->left] = true;
          q.push(curr->left);
        }
        if (curr->right && !vis[curr->right]) {
          vis[curr->right] = true;
          q.push(curr->right);
        }
        if (parents[curr] && !vis[parents[curr]]) {
          vis[parents[curr]] = true;
          q.push(parents[curr]);
        }
      }
    }

    vector<int> res;
    while (!q.empty()) {
      res.push_back(q.front()->val);
      q.pop();
    }
    return res;
  }
};
class Solution {
public:
  vector<int> ans;
  int distanceKHelper(TreeNode* root, TreeNode* target, int k, int i) {
    if (root == NULL)
      return -1;
    if (i == 0)
    {
      ans.push_back(root->val);
      return -1;
    }
    if (root == target) {
      if (k == 0) {
        ans.push_back(root->val);
        return -1;
      }
      distanceKHelper(root->left, target, k, k - 1);
      distanceKHelper(root->right, target, k, k - 1);
      return k - 1;
    }
    else {
      int left = distanceKHelper(root->left, target, k, i == -1 ? -1 : i - 1);
      int right = distanceKHelper(root->right, target, k, i == -1 ? -1 : i - 1);
      if (left == 0 || right == 0) {
        ans.push_back(root->val);
        return -1;
      }
      if (left != -1) {
        distanceKHelper(root->right, target, k, left - 1);
        return left - 1;
      }
      if (right != -1) {
        distanceKHelper(root->left, target, k, right - 1);
        return right - 1;
      }
      return -1;
    }
  }
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    distanceKHelper(root, target, k, -1);
    return ans;
  }
};
int main() {

  return 0;
}