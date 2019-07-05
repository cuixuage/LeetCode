/*
无论是何种遍历方式必然用到DFS思路
思路preorder:
1.stack 取出top元素(上一层的left)
2.加入本层的left,right
*/

#include "func.h"
vector<int> preorderTraversal(TreeNode* root){
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