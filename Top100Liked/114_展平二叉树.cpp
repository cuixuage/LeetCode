#include "func.h"
/*
二叉树展平为链表 
DFS: 按照root->right,root->left顺序加入stack
*/

//pre-order前序遍历
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

//按照前序遍历展平为链表
void flatten(TreeNode* root){
    if (root==NULL) return;
    stack<TreeNode*> s;
    TreeNode* pre = NULL;
    s.push(root);

    while(!s.empty()){
        TreeNode* cur = s.top();
        s.pop();
        // 前序遍历的处理操作位置
        //1. 父节点的right指向cur节点 && 更新pre
        if(pre != NULL){
            pre->right = cur;
            pre->left = NULL;
        }
        pre = cur;

        if(cur->right != NULL) s.push(cur->right);
        if(cur->left != NULL) s.push(cur->left);
    }
}