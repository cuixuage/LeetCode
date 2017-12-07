/*
�Ա�116��
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
�ռ�: �㶨�Ŀռ��С
*/

//˼·:BFS
//����һ��BFS���������ڵ�ָ���ǵ�ǰ����������ߣ�ͷ������һ��������ߵ�Ԫ�أ�β��������һ�������ұߵ�Ԫ�ء�
//�������ڽ�ָ���Ƶ���ǰ���𣬲������Ӽ������һ�����ӡ�
//�������Ҫ�����������ڿ����ƶ�����һ������Ϊ�����ϵ�Ѿ���ǰһ��������ˣ���

void connect(TreeLinkNode *root)
{
    TreeLinkNode *now, *tail, *head;

    now = root;
    head = tail = NULL;
    while(now)
    {
        if (now->left)
            if (tail) tail = tail->next =now->left;             //����  ��������ֵ
            else head = tail = now->left;
        if (now->right)
            if (tail) tail = tail->next =now->right;
            else head = tail = now->right;
        if(!(now = now->next))
        {
            now = head;
            head = tail=NULL;
        }
    }
}


//˼·:ˮƽ����  //C++
void connect(TreeLinkNode *root)
{
    while(root != NULL)
    {
        //����TreeLinkNode* tempchild = NULL; �޷�����ͨ�� ��Ϊ�䲻����next����
        TreeLinkNode* tempchild=new TreeLinkNode(0);
        TreeLinkNode* currentchild=tempchild;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                currentchild->next=root->left;
                currentchild = currentchild->next;
            }
            if(root->right!=NULL)
            {
                currentchild->next = root->right;
                currentchild=currentchild->next;
            }

            root = root->next;
        }
        root = tempchild->next;
    }

}

