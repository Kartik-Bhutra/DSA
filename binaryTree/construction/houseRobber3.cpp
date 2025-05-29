// https://leetcode.com/problems/house-robber-iii/
#include <bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution
{
  pair<int, int> dfs(TreeNode *root)
  {
    if (!root)
      return {0, 0};
    auto [tk1, nt1] = dfs(root->left);
    auto [tk2, nt2] = dfs(root->right);
    int tk = nt1 + nt2 + root->val;
    int nt = max({tk1 + tk2, tk2 + nt1, nt1 + nt2, nt2 + tk1});
    return {tk, nt};
  }

public:
  int rob(TreeNode *root)
  {
    auto [m1, m2] = dfs(root);
    return max(m1, m2);
  }
};
int main()
{

  return 0;
}