/*
之字形打印二叉树
第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推

思路1:
dfs 前序遍历
1.传递的level变量记录层级 level%2得到顺序
思路2:
BFS + queue每次仅仅遍历一层
1.level记录层级
*/

//DFS
#include "func.h"
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    dfsHelper(ans,root,0);
    return ans;
}
void dfsHelper(vector<vector<int>>& ans,TreeNode* root, int level){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(vector<int>{});
    }
    //1.
    if(level%2==0) ans[level].push_back(root->val);
    else ans[level].insert(ans[level].begin(),root->val);
    dfsHelper(ans,root->left,level+1);
    dfsHelper(ans,root->right,level+1);
}

//BFS
vector<vector<int>> Print(TreeNode* root){
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root==NULL) return ans;
    int level = 0;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> tmp;
        while(levelSize--){
            TreeNode* top = q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            //1.
            if(level%2==0)
                tmp.push_back(top->val);
            else
                tmp.insert(tmp.begin(),top->val);
        }
        level++;
        ans.push_back(tmp);
    }
    return ans;
}