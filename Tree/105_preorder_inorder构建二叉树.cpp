    /*�Ա�144 145 94 */
//ͨ��ǰ����� ���������ȡ������
//����һ��   �õ�������������������

//˼·: �ݹ�preorder��һ���ڵ�Ϊ���ڵ� ��inorder��Ѱ����root
//�������нڵ���û���ظ�valֵ

TreeNode* buildTree(vector<int> & preorder,vector<int> inorder){
    return helper(0,0,inorder.size()-1,preorder,inorder);
}

/*
����:��ǰ����root�ڵ�λ��(preorder��Ѱ��)
     ��ǰ��������Ԫ�ص���ʼ���յ�λ��
     preorder inorder����
*/
TreeNode* helper(int prestart,int instart, int inend, vector<int>& preorder, vector<int>& inorder){
    if(prestart > preorder.size()-1 || instart > inend)
        return NULL;
    TreeNode* root = new TreeNode(preorder[prestart]);      //root����preorder
    int idx=0;                                             //��ǰ������root�ڵ�����inorder���
    for(int i=instart;i<=inend;i++)                        //С�ڵ���
        if(inorder[i] == root->val)
            idx = i;
    //������
    root->left = helper(prestart+1,instart,idx-1,preorder,inorder);
    //������
    root->right = helper(prestart+idx-instart+1,idx+1,inend,preorder,inorder);
    //ע����������root�ڵ�λ��

    return root;
}
