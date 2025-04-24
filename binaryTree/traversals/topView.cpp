// https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
using namespace std;
vector<int> getTopView(Tree* root) {
  if (root == nullptr)
    return {};

  queue<pair<Tree*, int>> q;
  int leftMost = 0, rightMost = 0;
  q.push(make_pair(root, 0));
  while (!q.empty()) {
    pair<Tree*, int> front = q.front();
    q.pop();
    Tree* node = front.first;
    int hd = front.second;

    leftMost = min(leftMost, hd);
    rightMost = max(rightMost, hd);

    if (node->left != nullptr)
      q.push(make_pair(node->left, hd - 1));
    if (node->right != nullptr)
      q.push(make_pair(node->right, hd + 1));
  }

  int width = rightMost - leftMost + 1;
  vector<int> res(width, -1);
  int offset = -leftMost;
  q.push(make_pair(root, 0));
  while (!q.empty()) {
    pair<Tree*, int> front = q.front();
    q.pop();
    Tree* node = front.first;
    int hd = front.second;

    int index = hd + offset;
    if (res[index] == -1) {
      res[index] = node->val;
    }

    if (node->left != nullptr)
      q.push(make_pair(node->left, hd - 1));
    if (node->right != nullptr)
      q.push(make_pair(node->right, hd + 1));
  }

  return res;
}

int main() {

  return 0;
}