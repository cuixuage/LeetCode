/*
判断二叉树路径和 是否存在等于给定值的可能性
路径定义:  从根节点到叶子节点的完整路径
思路1：
DFS 要求:
1.到达叶子节点时,同时保证sum和等于给定值

思路2:
BFS
每一层的节点的val记录着 "路径和",从root节点到当前节点的和
要求:
1.到达叶子节点时
2.同时保证sum和等于给定值
*/

#include "func.h"
//DFS 
//int sum参数传递
bool hasPathSum(TreeNode* root, int sum){
    if(root==NULL) return false;
    //1.val==sum && 此节点是叶子节点 
    if(root->val==sum && !root->left && !root->right) return true;
    bool left = hasPathSum(root->left,sum - root->val);
    bool right = hasPathSum(root->right, sum - root->val);
    //2.
    return left || right;
}

//BFS
//更好理解  缺点: 修改了树的结构
bool hasPathSum(TreeNode* root, int sum){
    if(root==NULL) return false;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
        //1. 2. 到达叶子节点
        if(!top->left && !top->right && top->val==sum) return true;
        if(top->left){
            top->left->val += top->val;
            q.push(top->left);
        }
        if(top->right){
            top->right->val += top->val;
            q.push(top->right);
        }
    }
    return false;
}