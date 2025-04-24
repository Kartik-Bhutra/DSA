// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
#include<bits/stdc++.h>
#include "../traversals/tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
class Solution {
  private:
      vector<vector<int>> pts;
      int left = 0, right = 0;
      void trav(TreeNode* node, int x, int y){
          if(node == nullptr) return;
          pts.push_back({x,y,node->val});
          left = min(left,x);
          right = max(right,x);
          trav(node->left,x-1,y+1);
          trav(node->right,x+1,y+1);
          return;
      }
  
  public:
      vector<vector<int>> verticalTraversal(TreeNode* root) {
          trav(root,0,0);
          vector<vector<int>> ans(abs(left)+right+1);
          sort(pts.begin(),pts.end());
          for(int i=0; i<pts.size(); i++){
              ans[pts[i][0]+abs(left)].push_back(pts[i][2]);
          }
          return ans;
      }
  };
int main(){
  
  return 0;
}