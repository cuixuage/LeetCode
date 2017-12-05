
/*144��preorder 145��postorder 103�ⰴ�����*/
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack;    //�������Ľ��
    myStack.push(root);
    if(root==NULL) return result;           //�������node������left����Խ��
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top();     //�˽ڵ���ʱ��mystack����ɾ�� ����preorder
        if(node->left!=NULL)
        {
            myStack.push(node->left);
            node->left=NULL;
        }else{                      //node������������ ����root->val
            result.push_back(node->val);
            myStack.pop();          //�Ӵ�������㼯����ɾ���˽ڵ�
            if(node->right) myStack.push(node->right);
        }
    }
    return result;
}
