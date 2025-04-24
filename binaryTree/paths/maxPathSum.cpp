// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/ 
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  int solve(TreeNode* root, int& maxi) {
    if (root == nullptr) {
      return 0;
    }
    int leftSum = max(0, solve(root->left, maxi));
    int rightSum = max(0, solve(root->right, maxi));
    int currentPathSum = root->val + leftSum + rightSum;
    maxi = max(maxi, currentPathSum);
    return root->val + max(leftSum, rightSum);
  }

  int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
  }
};
int main() {

  return 0;
}