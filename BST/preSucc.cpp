// https://www.naukri.com/code360/problems/predecessor-and-successor-in-bst_893049?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
#include "tree.hpp"
typedef Tree TreeNode;
typedef Tree Node;
using namespace std;
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1;
    int successor = -1;
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (key > temp->val)
        {
            predecessor = temp->val;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    temp = root;
    while (temp != NULL)
    {
        if (key >= temp->val)
        {
            temp = temp->right;
        }
        else
        {
            successor = temp->val;
            temp = temp->left;
        }
    }
    return make_pair(predecessor, successor);
}
int main(){
  return 0;
}