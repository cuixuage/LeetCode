/*
判定给出的树是否为平衡二叉树
思路idea: 
如何得到左右子树的深度,判断其相差值是否不超过1
见39_树的深度.cpp
*/
#include "func.h"

/*
O(N^2) 两重循环
对于每一个节点计算其对应的树深度
*/
int TreeDepth(TreeNode* root){
    if(root==NULL) return 0;
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    return std::max(left,right)+1;
}

bool isBalanced(TreeNode* root){
    if(root == NULL) return true;
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    if(left-right>1 || right-left<-1)   return false;
    //只要有一个子树是false 最终的结果就是false
    return isBalanced(root->left) && isBalanced(root->right);   
}

/*
O(N)时间复杂度
自下而上的思路  避免在子树上重复计算
*/
class Solution{
public:
    bool isBalanced(TreeNode* root){
        TreeDepth(root);
        return flag;
    }
private:
    bool flag = true;               
    int TreeDepth(TreeNode* root){
        if(root == NULL) return 0;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        if(std::abs(left-right)>1)
            flag = false;
        return 1+std::max(left,right);
    }
}