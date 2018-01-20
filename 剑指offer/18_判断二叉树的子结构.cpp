//�ж϶�����A�Ƿ���԰���������B
bool judge(BinaryTree* A,BinaryTree* B){
    bool result = false;
    if(A!=NULL || B!=NULL){
        if(A->val == B->val)    //�ҵ���ֵͬ�ĸ��ڵ�
            result = haveTree(A,B);
        if(!result)             //�������ݹ�
            result = judge(A->left,B);
        if(!result)
            result = judge(A->right,B);
    }
    return result;
}
//�ж���ͬ���ڵ������ A�Ƿ����B
bool haveTree(BinaryTree* A,BinaryTree* B){
    if(B==NULL) return true;
    if(A==NULL) return false;
    if(A->val!=B->val) return false;
    return haveTree(A->left,B->left) &&         //�ؼ�
            haveTree(B->right,B->right);
}

//�ƹ�2
//�ж�A B�������Ƿ���ͬ   leetcode100
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL||q==NULL) return p==q;

    if(p->val != q->val) return false;
    //�ֱ��ȡ�ݹ�����������֧
    bool ll = isSameTree(p->left,q->left);
    bool rr = isSameTree(p->right,q->right);
    //���Ϸ���boolֵ��ֻҪ��һ��false�ͻ���Զ��false
    return ll&rr;
}

