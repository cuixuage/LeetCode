/*
第k个最小的元素
思路1:
O(N)空间 O(N)时间
二叉查找 搜索树的中序排列是递增的
思路2:
stack进行中序遍历

*/
#include "func.h"

//中序遍历
int KthSmallest(TreeNode* root, int k){
    vector<int> inorder;
    KthSmallest(root,inorder);
    return inorder[k-1];
}

void KthSmallest(TreeNode* root, vector<int>& inorder){
    if(root==NULL) return;
    KthSmallest(root->left,inorder);
    inorder.push_back(root->val);
    KthSmallest(root->right,inorder);
}

//time O(K)???  space O(1)
//不不不  应该还是O(N)
int kthSmallest(TreeNode* root,int k){
    TreeNode* target = kthHelper(root,k);
    return target->val;
}
//中序遍历target
TreeNode* kthHelper(TreeNode* root,int& k){         //传递引用相当于别名
    TreeNode* target = NULL;
    if(root->left!=NULL)
        target = kthHelper(root->left,k);
    if(target==NULL){
        if(k==1) target = root;
        k--;
    }
    if(target==NULL && root->right!=NULL)
        target = kthHelper(root->right,k);
    return target;
}