/*
二叉树的深度
思路:
递归,根节点的深度等于max(left,right)+1
*/

#include "func.h"

int TreeDepth(TreeNode* root){
    if(root==NULL) return 0;
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    return std::max(left,right)+1;
}
