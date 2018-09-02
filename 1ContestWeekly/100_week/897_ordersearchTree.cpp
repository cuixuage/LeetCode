#include "func.h"

/*
给定二叉搜索树  重新排列
要求min Value作为root,同时没有子树<==>顺序排列
*/

//注意:  binarySearch的inorder 是单调递增序列
//Accept

/*
class Solution{
public:
    TreeNode* increasingBST(TreeNode* root){
        getInorder(root);
        if(inorder.size()<= 1) return root;
        inorder[inorder.size()-1]->left = NULL;
        inorder[inorder.size()-1]->right = NULL;
        for(int i=0;i<inorder.size()-1;i++){
            inorder[i]->left = NULL;
            inorder[i]->right = inorder[i+1];
        }
    }


private:
    vector<TreeNode*> inorder;
    void getInorder(TreeNode* root){
        if(root==NULL) return;
        getInorder(root->left);
        inorder.push_back(root);
        getInorder(root->right);
    }
};
*/

