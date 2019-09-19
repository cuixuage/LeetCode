#include "func.h"
/*
BST 二叉搜索树
给定数字n   返回1...n可以构成的所有BST(不包括相同的BST)
e.g. 123的排列组合最终只能生成5种二叉树
*/

//任何一个节点都能当做root  再递归左右两侧 最终组合(left right子树)的可能性
vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> ans;
    if(n==0) return ans;
    return generateTree(1,n);
}
vector<TreeNode*> generateTree(int from,int to){
    //每一轮迭代  变量都是新的
    vector<TreeNode*> ans;
    
    if(to - from <0) ans.push_back(NULL);               //e.g. 213 231只能生成一个子树
    if(to - from ==0) ans.push_back(new TreeNode(from));
    if(to - from > 0){
        for(int i=from;i<=to;i++){
            //left right所有可能的子树  用vector<root>保存起来
            vector<TreeNode*> l = generateTree(from,i-1);
            vector<TreeNode*> r = generateTree(i+1,to);
            
            //类似于后序遍历  将root节点所有可能的左右子树做拼接并保存到ans中
            for(auto lr : l){
                for(auto rr : r){
                    TreeNode *root = new TreeNode(i);
                    root->left = lr;
                    root->right = rr;
                    ans.push_back(root);
                }
            }
        }
    }
    return ans;
}



//Error  思路不清  递归两侧左右子树应该返回vector<TreeNode*>
// public:
//     vector<TreeNode*> generateTrees(int n){
//         vector<TreeNode*> ans;
//         return traverse(ans,1,n);
//     }
// 
// private:
//     int traverse(vector<TreeNode*>& ans, int m,int n){
//         //递归终止条件
//         if(m>n) return 0;
//         if(m==n) return m;
//         for(int i=m;i<=n;i++){
//             TreeNode* tmp = new TreeNode(m);
//             int left = traverse(ans,1,m-1);
//             int right = traverse(ans,m+1,n);
//             tmp->left = left==0 ? NULL:new TreeNode(left);
//             tmp->right = right==0 ? NULL:new TreeNode(right);
//             ans.push_back(tmp);
//         }
//         return 0;
//     }
