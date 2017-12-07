/*���������Ķ�������˵,��ÿ��node->next������ȷ�ĸ���
ע��:ÿһ�㼶�����Ҳ���->next �޷�����
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


//����1: �ݹ�
public void connect(TreeLinkNode root)
{
    if(root == null)    return;

    if(root.left != null)           //����left��Ȼ��right,����left->next
    {
        root.left.next = root.right;
        if(root.next != null)       //���Ը���root->right->next == root->next->left
            root.right.next = root.next.left;
    }

    connect(root.left);
    connect(root.right);
}

//�ǵݹ���ʽ �ռ�O(1)
public void connect(TreeLinkNode* root)
{
    TreeLinkNode* level_start=root;
    while(level_start!=NULL)                //���㼶����
    {
        TreeLinkNode* cur=level_start;      //���浱ǰ��ʼλ��
        while(cur!=NULL)
        {
            if(cur->left!=NULL) cur->left->next=cur->right;
            if(cur->right!=NULL && cur->next!=NULL) cur->right->next=cur->next->left;

            cur=cur->next;
        }
        level_start=level_start->left;      //����ÿһ��start node
    }
}
