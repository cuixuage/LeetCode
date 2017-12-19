//对比 94 144 145
//对比 105 106
//对比 107逆序层级顺序 102顺序层级顺序

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    travel(root,ans,0);
    return ans;
}

void travel(TreeNode* curr,vector<vector<int>>& ans, int level){
    if(curr == NULL) return;
    if(ans.size() == level){
        vector<int> temp;
        ans.push_back(temp);
    }
    if(level%2==0)
        ans[level].push_back(curr->val);
    else            //奇数 从头部插入
        ans[level].insert(ans[level].begin(),curr->val);

    travel(curr->left,ans,level+1);
    travel(curr->right,ans,level+1);
}
