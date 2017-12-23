bool isSameTree(TreeNode *p, TreeNode *q)
{
    if(p==NULL||q==NULL) return p==q;

    if(p->val != q->val) return false;

    bool ll = isSameTree(p->left,q->left);
    bool rr = isSameTree(p->right,q->right);        //���淵��ֵ�ܹؼ�

    //���Ϸ���boolֵ��ֻҪ��һ��false�ͻ���Զ��false
    return ll&rr;
}
