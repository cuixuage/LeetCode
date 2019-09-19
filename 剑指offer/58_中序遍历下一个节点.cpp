/*
给定二叉树TreeNode* root,寻找某个节点的中序遍历下一个节点
思路1:
按照中序遍历保存每一个指针,再遍历寻找
思路2：
通过parent指针寻找,核心在于分清楚中序遍历的情况
2.1如果一个节点有右子树，那么它的下一个节点就是它的右子树中的最左子节点。
2.2如果没有右子树，且它是父节点的左子节点，那么它的下一个节点就是它的父节点。
2.3如果一个节点即没有右子树，并且它还是父节点的右子节点。我们可以沿着指向父节点的指针一直向上遍历，直到找到一个是它父节点的左子节点的节点。如果这样的节点存在，那么这个节点的父节点就是我们要找的下一个节点
如果一个节点不满足上述所有情况，那么它应该就是中序遍历的最后一个节点。所以返回NULL

*/
#include "func.h"
struct BinaryTreeNode {
    int val;
    BinaryTreeNode* parent;     //其parant节点
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* GetNext(BinaryTreeNode* root){      //查找root节点的下一个节点
    if(root == NULL) return NULL;
    BinaryTreeNode* next_node = NULL;
    //2.1
    if(root->right!=NULL){
        BinaryTreeNode* next = root->right;
        while(next->left!=NULL)    next = next->left;
        return next;
    }else{
    //2.2 2.3
        BinaryTreeNode* parent = root->parent;
        BinaryTreeNode* cur = root;
        while(parent!=NULL && cur==parent->right){      //2.3 其是父节点的右子节点
            cur = parent;
            parent = parent->parent;            //存在parent指针,指向父节点
        }
        return parent;
    }
    return NULL;
}