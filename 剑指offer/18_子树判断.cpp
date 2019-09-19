/*
判断B是不是A的子树
思路：
1.寻找same root val
2.同一个root下. left,right子树val
*/

#include "func.h"

bool isSubtree(TreeNode* A,TreeNode* B){
    bool ans = false;
    if(A!=NULL && B!=NULL){
        if(A->val == B->val) ans = isSame2(A,B);        //先找到B的根节点在A的位置
        if(!ans) ans = isSubtree(A->left,B);
        if(!ans) ans = isSubtree(A->right,B);
    }
    return ans;
}

//相同根节点情况下 A是否包含B
bool isSame2(TreeNode* A,TreeNode* B){
    if(B==NULL) return true;
    if(A==NULL) return false;
    if(A->val != B->val) return false;
    return isSame2(A->left,B->left) && isSame2(A->right,B->right);
}



//leetcode 572
bool isSubtree(TreeNode* A,TreeNode* B){
    if(A==NULL) return false;
    //2.
    if(isSame(A,B)) return true;
    //1. 递归函数是isSubtree
    return isSubtree(A->left,B) || isSubtree(A->right,B);
}
//推广 leetcode100题目 判断两个树是否相同
bool isSame(TreeNode* A, TreeNode* B){
    if(A==NULL && B==NULL) return true;
    if(A==NULL || B==NULL) return false;
    if(A->val != B->val) return false;
    ///////////////////////////////////////////注意递归对比的子树
    return isSame(A->left,B->left) && isSame(A->right,B->right);
}


