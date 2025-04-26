// https://www.naukri.com/code360/problems/time-to-burn-tree_630563?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
void inorder(TreeNode* root, unordered_map<int, vector<int>>& m)
{
  if (root)
  {
    inorder(root->left, m);
    if (root->left)
    {
      m[root->val].push_back(root->left->val);
      m[root->left->val].push_back(root->val);
    }
    if (root->right)
    {
      m[root->val].push_back(root->right->val);
      m[root->right->val].push_back(root->val);
    }
    inorder(root->right, m);
  }
}
int timeToBurnTree(TreeNode* root, int start)
{
  unordered_map<int, vector<int>> m;
  inorder(root, m);
  queue<int> q;
  q.push(start);
  int count = 0;
  unordered_map<int, bool> visited;
  visited[start] = true;
  while (!q.empty())
  {
    count++;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
      int node = q.front();
      q.pop();
      for (auto i : m[node])
      {
        if (!visited[i])
        {
          q.push(i);
          visited[i] = true;
        }
      }
    }
  }
  return count - 1;
}
class Triplet
{
public:
  int max, above, below;
  Triplet(int max, int above, int below)
  {
    this->max = max;
    this->above = above;
    this->below = below;
  }
};
Triplet timeToBurnTreeHelper(TreeNode* root, int start)
{
  if (root == NULL)
  {
    return Triplet(-1, -1, 0);
  }
  Triplet left = timeToBurnTreeHelper(root->left, start);
  Triplet right = timeToBurnTreeHelper(root->right, start);
  Triplet ans = Triplet(-1, -1, 0);
  if (root->val == start)
  {
    int below = max(left.below, right.below);
    ans.max = below;
    ans.above = 0;
    ans.below = below;
  }
  else if (left.above != -1)
  {
    ans.max = max(left.max, max(left.below, left.above + right.below + 1));
    ans.above = left.above + 1;
    ans.below = left.below;
  }
  else if (right.above != -1)
  {
    ans.max = max(right.max, max(right.below, right.above + left.below + 1));
    ans.above = right.above + 1;
    ans.below = right.below;
  }
  else
  {
    ans.max = -1;
    ans.above = -1;
    ans.below = max(left.below, right.below) + 1;
  }
  return ans;
}
int timeToBurnTree(TreeNode* root, int start)
{
  Triplet ans = timeToBurnTreeHelper(root, start);
  return ans.max;
}
int main() {
  return 0;
}