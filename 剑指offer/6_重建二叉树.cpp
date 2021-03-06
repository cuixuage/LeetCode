/* 
前序遍历和中序遍历重构二叉树,假设所有节点中没有重复val值
注意:helper函数传递的参数 && 节点位置计算
1.确定root val & index
2.左右的子树的起点位置 和 终点位置
3.递归
*/

#include "func.h"

TreeNode* buildTree(vector<int>& preorder,vector<int>&inorder){
    return helper(0,0,inorder.size()-1,preorder,inorder);
}

//先算一个length长度


递归参数: Ps,Pe,Is,Ie
Ps==root,在Is,Ie之间寻找根节点的index
左子树的长度 = index-Is
left = (Ps+1, Ps+index-Is, Is, index-1) 
right = (ps+index-Is+1,Pe,index+1,Ie)




//preorder[prestart]是root位置  
TreeNode* helper(int prestart,int instart,int inend, vector<int>& preorder,vector<int>& inorder){
    if(prestart>preorder.size()-1 || instart > inend)
        return NULL;
    //1.
    TreeNode* root = new TreeNode(preorder[prestart]);
    //2.
    int idx = 0;
    for(int i=instart;i<=inend;i++)
        if(inorder[i]==root->val)   idx = i;
    //3.
    root->left = helper(prestart+1,instart,idx-1,   preorder,inorder);
    root->right = helper(prestart+idx-instart+1,idx+1,inend,   preorder,inorder);
    return root;
}