#include "func.h"
/*
最近的共同父节点  假设元素都是不相同的
思路: 保存root->结点得路径,这两条路径的最后一个公共节点即为公共父节点
转化:
root->node的路径问题
*/

/////////////////////////////////////AC
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

//递归
void findPath(TreeNode* root,vector<TreeNode*>& mypath,vector<TreeNode*>& store_path,int val){
    if(root==NULL) return ;
    mypath.push_back(root);
    if(root->val == val) {store_path = mypath;return;}
    if(root->left) findPath(root->left,mypath,store_path,val);
    if(root->right) findPath(root->right,mypath,store_path,val);
    mypath.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL) return NULL;
    TreeNode* root_tmp = root;
    vector<TreeNode*> path_p;
    vector<TreeNode*> path_q;
    vector<TreeNode*> store_p;
    vector<TreeNode*> store_q;
    findPath(root_tmp,path_p,store_p,p->val);
    findPath(root,path_q,store_q,q->val);
    int index = 0;
    for(int i=0;i<std::min(store_p.size(),store_q.size()); i++){
        if(store_p[i]->val == store_q[i]->val)
            index = i;
        else
            break;
    }
    return store_p[index];
}