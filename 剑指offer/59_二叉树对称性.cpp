/*
对称性定义:二叉树 和 二叉树的镜像树相同
e.g. 左子树的最左侧节点==右子树的最右侧节点
思路1：
生成镜像树 再判断两颗树是否相同

思路2:
对左右子树进行带有NULL的前序遍历,如果相同则是对称性的

思路3:
思考: 画图理解为何需要颠倒left right两次
递归遍历(root->left,root->right) && (root->right,root->left)
*/

#include "func.h"

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return helper(root->left,root->right);
}

bool helper(TreeNode* p1,TreeNode* p2){
    if(p1==NULL &&p2==NULL) return true;
    else if(p1==NULL || p2==NULL) return false;
    else if(p1->val != p2->val) return false;

    // else return true;  //可不能加上
    //画图理解"交换left right的原因"
    return helper(p1->left,p2->right) &&helper(p1->right,p2->left);
}