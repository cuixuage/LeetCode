
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


//思路2  仔细理解
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> rootStack;
    vector<int> inorder;
    TreeNode* p = root;         //init
    while(!rootStack.empty() || p!=nullptr){
        if(p!=nullptr){
            rootStack.push(p);
            p=p->left;
        }
        else{
            TreeNode* node = rootStack.top();
            rootStack.pop();
            inorder.push_back(node->val);  //在所有left结点加入stack后
            p = node->right;
        }
    }
    return inorder;
}

//类似思路2  仔细理解  中序遍历
vector<int> inorderTraversal(TreeNode* root){
    vector<int> inorder;
    stack<TreeNode*> s;
    if(root == NULL) return inorder;
    TreeNode* pre = root;          //初始化的注意点
    while(pre!=NULL || !s.empty()){
        while(pre!=NULL){
            s.push(pre);
            pre = pre->left;
        }
        TreeNode* top = s.top();
        s.pop();
        inorder.push_back(top->val);
        pre = top->right;               //理解top节点的含义
    }
    return inorder;
}