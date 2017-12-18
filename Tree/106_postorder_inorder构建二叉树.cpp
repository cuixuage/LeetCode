
//ע����Ŀ���ȸ���inorder˳�� �������postorder
//һ�� AC

//�Ľ� ÿ�εݹ��е�ѭ�����Ը�Ϊhashmap
//���� postorder��ȷ����root->val  O(1) �õ����Ӧinorderλ��

TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
    return helper(postorder.size()-1,0,inorder.size()-1,postorder,inorder);
}

TreeNode* helper(int postend,int is,int ie,vector<int>& postorder,vector<int>& inorder){
    if(postend <0 || is>ie)
        return NULL;
    TreeNode* root = new TreeNode(postorder[postend]);
    int idx=0;
    for(int i=is;i<=ie;i++)
        if(inorder[i] == root->val)
            idx=i;
            //1.postorder��һ�㼶��rootλ��
            //2.inorder��һ�㼶������Ԫ��start endλ��
    root->left = helper(postend-(ie-idx)-1,is,idx-1,postorder,inorder);
    root->right = helper(postend-1,idx+1,ie,postorder,inorder);
    return root;
}
