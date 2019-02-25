/*
两个二叉树,合并成新的二叉树
如果新的二叉树的位置,两个旧的二叉树都存在节点,则将它们的和相加
思路:
1.
2.此t1 t2必有一个不为空, 算得val==0 也需要构建节点
*/
#include "func.h"
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
    //1.
    if(t1==NULL && t2==NULL) return NULL;
    //2.
    int val = (t1==NULL?0:t1->val) + (t2==NULL?0:t2->val);
    TreeNode* newNode = new TreeNode(val);

    newNode->left = mergeTrees(t1==NULL?NULL:t1->left, t2==NULL?NULL:t2->left);
    newNode->right = mergeTrees(t1==NULL?NULL:t1->right, t2==NULL?NULL:t2->right);
    
    return newNode;
}