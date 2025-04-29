// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
  public:
      TreeNode* bst(vector<int>& preorder,int lb,int ub,int &index){
          if(index==preorder.size() ||preorder[index]<lb || preorder[index]>ub){
              return NULL;
          }
          TreeNode* root=new TreeNode(preorder[index++]);
          root->left=bst(preorder,lb,root->val,index);
          root->right=bst(preorder,root->val,ub,index);
          return root;
      }
      TreeNode* bstFromPreorder(vector<int>& preorder) {
          int lb=INT_MIN;
          int ub=INT_MAX;
          TreeNode* root;
          int index=0;
          root=bst(preorder,lb,ub,index);
          return root;
          
      }
  };
int main(){
  
  return 0;
}