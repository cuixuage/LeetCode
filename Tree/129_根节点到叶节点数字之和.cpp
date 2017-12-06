/*
For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
*/

//思路: 1.全局变量保存最终结果 2.sum是当前遍历的根节点的val
//优化:  不要使用全局变量

int sumNumbers(TreeNode* root)
{
    return helper(root,0) ;
}

int helper(TreeNode* root, int sum)
{
    if (root == NULL) return 0;

    //sum = sum * 10 + root->val;
    int newsum = sum*10 + root->val;
    if (root->left == NULL && root->right == NULL)
    //    return sum;
        return newsum;
    //return helper(root->left, sum)+helper(root->right, sum);
    return helper(root->left, newsum)+helper(root->right, newsum);
}
/*

#include "func.h"
public:
int total;
int sumNumbers(TreeNode* root)
{
    total = 0;
    helper(root, 0);
    return total;
}

void helper(TreeNode* root, int sum)
{
    if (root == NULL) return;

    sum = sum * 10 + root->val;

    if (root->left == NULL && root->right == NULL)
    {
        total += sum;
        return;
    }

    helper(root->left, sum);
    helper(root->right, sum);
}
*/
