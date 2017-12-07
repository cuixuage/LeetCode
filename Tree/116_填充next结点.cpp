/*对于完整的二叉树来说,将每个node->next进行正确的更新
注意:每一层级的最右侧结点->next 无法更新
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


//方案1: 递归
public void connect(TreeLinkNode root)
{
    if(root == null)    return;

    if(root.left != null)           //存在left必然存right,更新left->next
    {
        root.left.next = root.right;
        if(root.next != null)       //可以更新root->right->next == root->next->left
            root.right.next = root.next.left;
    }

    connect(root.left);
    connect(root.right);
}

//非递归形式 空间O(1)
public void connect(TreeLinkNode* root)
{
    TreeLinkNode* level_start=root;
    while(level_start!=NULL)                //按层级遍历
    {
        TreeLinkNode* cur=level_start;      //保存当前起始位置
        while(cur!=NULL)
        {
            if(cur->left!=NULL) cur->left->next=cur->right;
            if(cur->right!=NULL && cur->next!=NULL) cur->right->next=cur->next->left;

            cur=cur->next;
        }
        level_start=level_start->left;      //更新每一层start node
    }
}
