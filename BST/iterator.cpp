// 
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class BSTIterator {
  stack<TreeNode *> myStack;
public:
  BSTIterator(TreeNode *root) {
      pushAll(root);
  }
  bool hasNext() {
      return !myStack.empty();
  }

  int next() {
      TreeNode *tmpNode = myStack.top();
      myStack.pop();
      pushAll(tmpNode->right);
      return tmpNode->val;
  }

private:
  void pushAll(TreeNode *node) {
      for (; node != NULL; myStack.push(node), node = node->left);
  }
};
int main(){
  
  return 0;
}