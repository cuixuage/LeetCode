
/*
思路  ==>  二叉树的最大直径
后序遍历时, 在root节点统计深度 or 权重和
*/

#include"func.h"

public:
int maxPathSum(TreeNode* root){
    int maxvalue = INT_MIN;
    maxPathDown(root,maxvalue); 
    return maxvalue;
}
private:
int maxPathDown(TreeNode* node, int& maxvalue){
    if(node==NULL) return 0;
    int left= std::max(0,maxPathDown(node->left,maxvalue));         //关键点:  如果权重为负数  会被丢弃掉
    int right = std::max(0,maxPathDown(node->right,maxvalue));
    maxvalue = std::max(maxvalue,left+right+node->val);             //后序遍历思路
    return std::max(left,right)+node->val;                         //最大直径问题:  return max(left,right)+1
}