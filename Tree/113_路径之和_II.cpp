/*返回 root到leaf之和等于sum 的路径节点序列*/
//思路: DFS(经典的回溯问题) 对比112题
//注释: DFS 仔细理解 递归时返回的顺序 以及 path.pop()位置

public:
vector<vector<int>> pathSum(TreeNode* root,int sum){
    vector<vector<int>> ans;
    vector<int> path;
    findPaths(root,sum,path,ans);  //传递引用
    return ans;
}
private:
void findPaths(TreeNode* node,int sum,vector<int>& path,vector<vector<int>>& ans){
    if(!node) return;
    path.push_back(node->val);
    if(!(node->left) && !(node->right)&& sum==node->val)
        ans.push_back(path);
        //仔细思考回溯（DFS）是如何解决问题的
    findPaths(node->left,sum-node->val,path,ans);
    findPaths(node->right,sum-node->val,path,ans);
    //注意pop_back的位置
    path.pop_back();
}
};
