
/*144题preorder 145题postorder 103题按层输出*/
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack;    //待遍历的结点
    myStack.push(root);
    if(root==NULL) return result;           //避免后面node不存在left结点而越界
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top();     //此节点暂时从mystack不能删除 区别preorder
        if(node->left!=NULL)
        {
            myStack.push(node->left);
            node->left=NULL;
        }else{                      //node不存在左子树 加入root->val
            result.push_back(node->val);
            myStack.pop();          //从待遍历结点集合中删除此节点
            if(node->right) myStack.push(node->right);
        }
    }
    return result;
}
