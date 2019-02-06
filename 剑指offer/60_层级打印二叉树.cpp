/* 
结果保存到二维数组vector<vector<int>> ans
思路1:
1.BFS遍历,queue
2.深刻理解 queue如何每次只保存一个层级

思路2:
1.DFS 递归
2.每次递归传递level变量
*/

#include "func.h"
//思路1 BFS 更好理解
vector<vector<int>> Print(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> ans;
    if(!root) return ans;
    q.push(root);               //1.
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> tmp;
        while(levelSize--){     //2. 遍历当前层级
            TreeNode* top = q.front();
            q.pop();
            tmp.push_back(top->val);
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        ans.push_back(tmp);
    }
    return ans;
}

//思路2 BFS level变量
vector<vector<int>> Print(TreeNode* root){
    vector<vector<int>> ans;
    levelHelper(ans,root,0);
    return ans;
}

void levelHelper(vector<vector<int>>& ans, TreeNode* curr, int level){
    if(curr==NULL) return;
    if(level==ans.size()){      //二维数组 新加一层
        ans.push_back(vector<int>{});
    }
    ans[level].push_back(curr->val);
    levelHelper(ans,curr->left,level+1);
    levelHelper(ans,curr->right,level+1);
}