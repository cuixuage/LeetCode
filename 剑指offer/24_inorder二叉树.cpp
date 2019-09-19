/*
无论是何种遍历方式必然用到DFS思路
思路1:
stack 
1.dfs出栈顺序是left->root->right 
2.当node->left不为空时加入stack,同时避免stack回溯到root时重复递归,将nod->left=NULL
缺点: 改变了原有的树结构

思路2：
stack + O(1)变量 避免改变原有树结构
*/

#include "func.h"
vector<int> inorderTraversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> s;
    if(root==NULL) return ans;
    s.push(root);
    while(!s.empty()){
        TreeNode* top = s.top();
        if(top->left){
            //1.
            s.push(top->left);
            top->left = NULL;
        }else{
            ans.push_back(top->val);
            s.pop();
            if(top->right) s.push(top->right);
        }
    }
    return ans;
}

//思路2  仔细理解
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> rootStack;
    vector<int> inorder;
    TreeNode* p = root;         //init
    while(!rootStack.empty() || p!=nullptr){
        if(p!=nullptr){
            rootStack.push(p);
            p=p->left;
        }
        else{
            TreeNode* node = rootStack.top();
            rootStack.pop();
            inorder.push_back(node->val);
            p = node->right;               //关键  更新pre到node的右子树 (画图理解节点p)  此时node节点是左子树的最后一个
        }
    }
    return inorder;
}

//类似思路2  仔细理解  中序遍历
vector<int> inorderTraversal(TreeNode* root){
    vector<int> inorder;
    stack<TreeNode*> s;
    if(root == NULL) return inorder;
    TreeNode* pre = root;          //初始化的注意点
    while(pre!=NULL || !s.empty()){
        while(pre!=NULL){
            s.push(pre);
            pre = pre->left;
        }
        TreeNode* top = s.top();
        s.pop();
        inorder.push_back(top->val);
        pre = top->right;               //理解top节点的含义
    }
    return inorder;
}