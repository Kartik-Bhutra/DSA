
// https://leetcode.com/problems/find-leaves-of-binary-tree/description/
#include <bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution
{
  vector<vector<int>> ans;

public:
  int dfs(TreeNode *u)
  {
    if (u == nullptr)
    {
      return -1;
    }
    int leftLevel = dfs(u->left);
    int rightLevel = dfs(u->right);
    int currentLevel =
        max(leftLevel, rightLevel) + 1;
    while (ans.size() <=
           currentLevel)
    {
      ans.push_back({});
    }
    ans[currentLevel].push_back(u->val);
    return currentLevel;
  }
  vector<vector<int>> findLeaves(TreeNode *root)
  {
    dfs(root);
    return ans;
  }
};
int main()
{

  return 0;
}