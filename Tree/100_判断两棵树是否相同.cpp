bool isSameTree(TreeNode *p, TreeNode *q)
{
    if(p==NULL||q==NULL) return p==q;

    if(p->val != q->val) return false;

    bool ll = isSameTree(p->left,q->left);
    bool rr = isSameTree(p->right,q->right);        //保存返回值很关键

    //不断返回bool值，只要有一个false就会永远是false
    return ll&rr;
}
