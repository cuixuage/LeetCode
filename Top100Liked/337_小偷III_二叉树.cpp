#include "func.h"
/*
0.错误解法
求非相连的层级和最大的值
vector<int> 保存每一层的值; ==> 寻找不相连非负整数的最大和
动态规划: DP(n) = max(d(n-1),  d(n-2) + nums[n])   关键

1.DFS
二叉树非相连节点之和的最大值  (max(root+孙子节点 ， 儿子节点))
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//0.错误解法
int rob(TreeNode* root) {
    if(root == NULL) return 0;
    if(!root->left && !root->right) return root->val;
    vector<int> levels;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int curent_len = q.size();
        int level = 0;
        while(curent_len--){
            TreeNode* tmp = q.front();
            q.pop();
            level += tmp->val;
            if(tmp->left)   q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        levels.push_back(level);
    }
    vector<int> ans(levels.size(),0);
    ans[0] = levels[0];
    ans[1] = std::max(levels[0],levels[1]);         //注意dp[0],dp[1]的初始化问题
    for(int i=2;i<levels.size();i++){
        ans[i] = std::max(ans[i-1],ans[i-2]+levels[i]);
    }
    return ans.back();
}

//1.
int rob(TreeNode* root){
    unordered_map<TreeNode*,int> hashmap;
    return robsub(root, hashmap);
}

int robsub(TreeNode* root, unordered_map<TreeNode*,int>& hashmap){
    if(root == NULL) return 0;
    if(hashmap.count(root)) return hashmap[root];       //每一个结点的最优的子结果
    int val = 0;
    if(root->left)
        val += robsub(root->left->left,hashmap) + robsub(root->left->right,hashmap);
    if(root->right)
        val += robsub(root->right->left,hashmap) + robsub(root->right->right,hashmap);
    val = std::max(val + root->val, robsub(root->left,hashmap) + robsub(root->right,hashmap));
    hashmap[root] = val;
    return val;
}