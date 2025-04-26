#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  vector<int> getPreorder(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;
    while (cur != NULL) {
      if (cur->left == NULL) {
        preorder.push_back(cur->val);
        cur = cur->right;
      }
      else {
        TreeNode* prev = cur->left;
        while (prev->right && prev->right != cur) {
          prev = prev->right;
        }
        if (prev->right == NULL) {
          prev->right = cur;
          cur = cur->left;
        }
        else {
          prev->right = NULL;
          preorder.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return preorder;
  }
};
int main() {
  return 0;
}