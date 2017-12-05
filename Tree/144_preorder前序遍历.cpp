/*144��preorder 94��inorder 103�ⰴ�����*/
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack;    //�������Ľ��
    myStack.push(root);          //initialize
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top();
        myStack.pop();                  //�Ӵ�������㼯����ɾ���˽ڵ�
        if(node!=nullptr)               //myStackҲ��push��NULL���  ��Ҫ�ж�
        {
            result.push_back(node->val);
            myStack.push(node->right);      //ע��˳��
            myStack.push(node->left);
        }
    }
    return result;

}
