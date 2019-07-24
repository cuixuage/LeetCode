/*
按照层级打印二叉树
本题返回值类型 vector<int>
而60题 返回值类型是vector<vector<int>>
*/

#include "func.h"

vector<int> PrintFromTopToBottom(TreeNode* root){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
        ans.push_back(top->val);
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    } 
    return ans;
}

//trick
// 每一层循环q.size()的大小的left,right =》BFS层级遍历