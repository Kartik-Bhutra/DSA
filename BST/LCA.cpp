// https://leetcode.com/problems/validate-binary-search-tree/
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    while (root)
    {
      if (root->val > p->val && root->val > q->val)
        root = root->left;
      else if (root->val < q->val && root->val < p->val)
        root = root->right;
      else
        return root;
    }
    return NULL;
  }
};
int main() {
  return 0;
}