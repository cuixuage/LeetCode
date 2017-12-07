/*
对比116题
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
空间: 恒定的空间大小
*/

//思路:BFS
//这是一个BFS遍历。现在的指针是当前级别的旅行者，头是最下一级的最左边的元素，尾巴是最下一级的最右边的元素。
//我们现在将指针移到当前级别，并在其子级填充下一级链接。
//（这里的要点是我们现在可以移动到下一个，因为这个关系已经在前一轮中填充了）。

void connect(TreeLinkNode *root)
{
    TreeLinkNode *now, *tail, *head;

    now = root;
    head = tail = NULL;
    while(now)
    {
        if (now->left)
            if (tail) tail = tail->next =now->left;             //连等  从右向左赋值
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


//思路:水平遍历  //C++
void connect(TreeLinkNode *root)
{
    while(root != NULL)
    {
        //但是TreeLinkNode* tempchild = NULL; 无法编译通过 因为其不存在next属性
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

