/*
一.
二叉搜索树: 最低公共父节点,DFS找到第一个root->val处于[node1,node2]之间的节点
二.
普通二叉树: 
1.拿到node1,node2到root的路径path1,path2
2.path1,path2中最后一个相同节点即为公共父节点
*/
#include "func.h"
//1. 回溯
void findPath(TreeNode* root,vector<TreeNode*>& mypath,vector<TreeNode*>& store_path,int val){
    if(root==NULL) return ;
    mypath.push_back(root);
    if(root->val == val) {store_path = mypath;return;}
    findPath(root->left,mypat h,store_path,val);
    findPath(root->right,mypath,store_path,val);
    mypath.pop_back();
}

TreeNode* getLowestNode(vector<TreeNode*>&path1,vector<TreeNode*>path2){
    int len = std::min(path1.size(),path2.size());
    int index = 0;
    for(int i=0;i<len;i++){
        if(path1[i]->val == path2[i]->val) index=i;   //寻找两个数组共用节点最后一个
        else break;
    }
    return path1[index];
}

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL) return NULL;
    TreeNode* root_tmp = root;
    vector<TreeNode*> path1;  //用于回溯
    vector<TreeNode*> path2;
    vector<TreeNode*> store1; //用于保存最终路径
    vector<TreeNode*> store2;
    findPath(root_tmp,path1,store1,p->val);
    findPath(root,path2,store2,q->val);
    auto parenet = getLowestNode(store1,store2);
    return parenet;
}