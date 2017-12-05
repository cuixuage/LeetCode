/*144题preorder 94题inorder 103题按层输出*/
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack;    //待遍历的结点
    myStack.push(root);          //initialize
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top();
        myStack.pop();                  //从待遍历结点集合中删除此节点
        if(node!=nullptr)               //myStack也被push了NULL结点  需要判断
        {
            result.push_back(node->val);
            myStack.push(node->right);      //注意顺序
            myStack.push(node->left);
        }
    }
    return result;

}
