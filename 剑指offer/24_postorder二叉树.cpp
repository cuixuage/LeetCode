/*
按照后序postorder打印二叉树；无论是何种遍历方式必然用到DFS思路
思路:
1. stack出栈顺序是 root->right->left
2. 转置数组ans,得到postorder left->right->root
*/
#include "func.h"
vector<int> postoerderTravelsal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> s;
    if(root==NULL) return ans;
    s.push(root);
    while(!s.empty()){
        TreeNode* top = s.top();
        s.pop();
        ans.push_back(top->val);
        //1.
        if(top->left) s.push(top->left);
        if(top->right) s.push(top->right);
    }
    //2.
    std::reverse(ans.begin(),ans.end());
    return ans;
}