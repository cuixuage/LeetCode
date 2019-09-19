
//判断 对称树
// 关键在于递归  helper(left->left,right->right) && helper(left->right,right->left);

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return helper(root->left,root->right);  //�������������� ��

}
int helper(TreeNode* left, TreeNode* right){
    if(!left || !right)
        return left==right;             //��left==right==NULL����true
    else if(left->val != right->val)
        return false;                   //ture������㷵��;  ����Ҫȫ���ݹ���ϲ��ܷ���true

    //�Գ��Եĵݹ�
    return helper(left->left,right->right) &&
            helper(left->right,right->left);
}


//�ǵݹ���ʽ����
https://leetcode.com/problems/symmetric-tree/discuss/
