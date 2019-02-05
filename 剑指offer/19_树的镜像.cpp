/*
镜像树  递归翻转左右节点(每次翻转父节点会连带子节点旋转)
思路idea:
前序遍历
*/

#include "func.h"

//递归
TreeNode* invertTree(TreeNode* root){
    if(root == NULL) return root;
    //swap
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    //递归左右子树
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

//循环
TreeNode* invertTree(TreeNode* root){
    std::stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* proot = stk.top();
        stk.pop();
        if(proot!=NULL){
            stk.push(proot->left);
            stk.push(proot->right);
            std::swap(proot->left,proot->right);
        }
    }
    return root;
}