/*
记录路径和 等于给定值的路径
DFS 回溯
1.叶子节点 + val等于sun时,为一条路径
2.回溯的位置
*/

#include "func.h"

class solution{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        vector<vector<int>> ans;
        vector<int> path;
        pathSum(root,sum,path,ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>&path,vector<vector<int>>& ans){
        if(root==NULL) return;
        //1.
        path.push_back(root->val);
        //3.
        if(!root->left && !root->right && sum==root->val)           ///////关键
            ans.push_back(path);
        pathSum(root->left,sum - root->val,path,ans);
        pathSum(root->right,sum - root->val,path,ans);
        //2. 回溯
        path.pop_back();
    }
}