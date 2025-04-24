// https://leetcode.com/problems/binary-tree-right-side-view/description/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ll;
    if (!root)
      return ll;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      TreeNode* rv = nullptr;
      while (n-- > 0) {
        rv = q.front();
        q.pop();
        if (rv->left)
          q.push(rv->left);
        if (rv->right)
          q.push(rv->right);
      }
      ll.push_back(rv->val);
    }
    return ll;
  }
};
int main() {

  return 0;
}