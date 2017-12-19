//判断一个二叉树 是否左右对称

//递归形式
bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return helper(root->left,root->right);  //传递左右子树的 根

}
int helper(TreeNode* left, TreeNode* right){
    if(!left || !right)
        return left==right;             //当left==right==NULL返回true
    else if(left->val != right->val)
        return false;                   //ture不能随便返回;  必须要全部递归完毕才能返回true

    //对称性的递归
    return helper(left->left,right->right) &&
            helper(left->right,right->left);
}


//非递归形式？？
https://leetcode.com/problems/symmetric-tree/discuss/
