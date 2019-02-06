/*
无论是何种遍历方式必然用到DFS思路
思路preorder:
1. root->left->right 注意出栈顺序
*/

#include "func.h"
vector<vector<int>> preorderTraversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> s;
    if(root == NULL) return ans;
    s.push(root);
    while(!s.empty()){
        TreeNode* top = s.top();
        s.pop();
        ans.push_back(top->val);
        //1.
        if(top->right) s.push(top->right);
        if(top->left) s.push(top->left);
    }
    return ans;
}