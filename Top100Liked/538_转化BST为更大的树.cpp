/*
二分查找树的每一个节点的val更新为其所有大于这个节点的val之和
思路:
1.平衡二叉树的中序遍历是升序的,我们根据right-root-left按照降序遍历
2.全局变量sum 按照降序序列不断加上当前的节点val
3.更新当前节点val
*/
#include "func.h"

class solution{
private:
    int sum = 0;        //也可以作为引用传递 e.g. 543题
public:
    TreeNode* convertBST(TreeNode* root){
        convert(root);
        return root;
    }
    void convert(TreeNode* root){
        if(root==NULL) return;
        //1.
        convert(root->right);
        //2. 3.
        sum += root->val;
        root->val = sum;
        convert(root->left);
    }
}