// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class BSTIterator {
  stack<TreeNode*> s;
  TreeNode* node;
  bool forward;
public:
  BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};
  bool hasNext() {
      return node != nullptr || !s.empty();
  }
  int next() {
      while (node || !s.empty()) {
          if (node) {
              s.push(node);
              node = forward ? node->left : node->right;
          }
          else {
              node = s.top();
              s.pop();
              int nextVal = node->val;
              node = forward ? node->right : node->left;
              return nextVal;
          }
      }

      return -1; 
  }
};
class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
      if (!root) return false;
      BSTIterator l(root, true);
      BSTIterator r(root, false);
      for (int i = l.next(), j = r.next(); i < j;) {
          int sum = i + j;
          if (sum == k) {
              return true;
          }
          else if (sum < k) {
              i = l.next();
          }
          else {
              j = r.next();
          }
      }
      return false;
  }
};
class Solution {
  void solve(TreeNode* root,vector<int> & vec){
      if(root==NULL) return ;
      solve(root->left,vec);
      vec.push_back(root->val);
      solve(root->right,vec);
  }
public:
  bool findTarget(TreeNode* root, int k) {
      vector <int> ans ;
       solve(root,ans);
    int i=0;
    int j = ans.size()-1;
    while(i<j){
      if(ans[i]+ans[j]==k) return 1;
      else if(ans[i] + ans[j] > k) j--;
      else if(ans[i] + ans[j] < k) i++;
     
    }
    return 0;
  }
};
int main(){
  
  return 0;
}