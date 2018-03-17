//判断二叉树A是否可以包含二叉树B
bool judge(BinaryTree* A,BinaryTree* B){
    bool result = false;
    if(A!=NULL || B!=NULL){
        if(A->val == B->val)    //找到相同值的根节点
            result = haveTree(A,B);
        if(!result)             //本函数递归
            result = judge(A->left,B);
        if(!result)
            result = judge(A->right,B);
    }
    return result;
}
//判断相同根节点情况下 A是否包含B
bool haveTree(BinaryTree* A,BinaryTree* B){
    if(B==NULL) return true;
    if(A==NULL) return false;
    if(A->val!=B->val) return false;
    return haveTree(A->left,B->left) &&         //关键
            haveTree(B->right,B->right);
}

//推广2
//判断A B两棵树是否相同   leetcode100
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL||q==NULL) return p==q;

    if(p->val != q->val) return false;
    //分别获取递归左右两个分支
    bool ll = isSameTree(p->left,q->left);
    bool rr = isSameTree(p->right,q->right);
    //不断返回bool值，只要有一个false就会永远是false
    return ll&rr;
}

