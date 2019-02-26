/*
定义:
二叉树中两两节点之间的最长距离 是二叉树的直径(可能并不会经过root节点)
思路:
1.  diameter作为全局变量(左右子树的深度求和 作比较)
2. 其他部分类似于求二叉树的深度
*/

#include "func.h"
int diameterOfBinaryTree(TreeNode* root){
    int diameter = 0;
    helper(root,diameter);
    return diameter;
}
//传递引用 避免了将diameter设置为全局变量
int helper(TreeNode* root, int& diameter){
    if(root==NULL) return 0;
    int ld = helper(root->left, diameter);
    int rd = helper(rot->right, diameter);
    //1.
    diameter = std::max(diameter, ld+rd);
    //2.
    return std::max(ld, rd)+1;      //类似于二叉树的深度题目
}