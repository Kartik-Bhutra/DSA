// https://www.naukri.com/code360/problems/largest-bst-subtree_893103?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
struct info
{
  bool isValid;
  int size, min, max;
};
info maxSize(TreeNode* currNode, int& maxBST)
{
  if (currNode == NULL)
  {
    return { true, 0, INT_MAX, INT_MIN };
  }
  info left = maxSize(currNode->left, maxBST);
  info right = maxSize(currNode->right, maxBST);
  info currInfo;
  currInfo.size = left.size + right.size + 1;
  currInfo.isValid = left.isValid & right.isValid;
  currInfo.isValid &= (currNode->val > left.max);
  currInfo.isValid &= (currNode->val < right.min);
  currInfo.min = min(min(left.min, right.min), currNode->val);
  currInfo.max = max(max(left.max, right.max), currNode->val);
  if (currInfo.isValid == true)
  {
    maxBST = max(maxBST, currInfo.size);
  }
  return currInfo;
}
int largestBST(TreeNode* root)
{
  int maxBST = 0;
  maxSize(root, maxBST);
  return maxBST;
}
int main() {
  return 0;
}