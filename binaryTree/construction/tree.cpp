// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
public:
  string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* curNode = q.front();
      q.pop();
      if (curNode == nullptr) {
        s += "#,";
      }
      else {
        s += to_string(curNode->val) + ",";
        q.push(curNode->left);
        q.push(curNode->right);
      }
    }
    return s;
  }
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      getline(s, str, ',');
      if (str != "#") {
        TreeNode* leftNode = new TreeNode(stoi(str));
        node->left = leftNode;
        q.push(leftNode);
      }
      getline(s, str, ',');
      if (str != "#") {
        TreeNode* rightNode = new TreeNode(stoi(str));
        node->right = rightNode;
        q.push(rightNode);
      }
    }
    return root;
  }
};
int main() {
  return 0;
}