
//����ݹ�˼��
int helper(TreeNode* curr)
{
    if(curr==NULL) return 0;
    int num = std::max(helper(curr->left),helper(curr->right))+1;
    return num;
}
//BFS  ÿһ�㼶������  ����������ײ�
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }

    return res;
}

//DFS
int maxDepth(TreeNode* root){
    if(root==NULL) return 0;
    stack<TreeNode*> mystack;
    stack<int> myvalue;
    int maxNum=0;
    mystack.push(root);
    myvalue.push(1);
    while(!mystack.empty()){
        TreeNode* curr = mystack.top();
        int temp = myvalue.top();
        mystack.pop();
        myvalue.pop();

        maxNum = std::max(temp,maxNum);
        //ע�� ��������������Ϊ��ʱ������������ͬ��ֵ == temp+1
        if(curr->left!=NULL){
            mystack.push(curr->left);
            myvalue.push(temp+1);
        }
        if(curr->right!=NULL){
            mystack.push(curr->right);
            myvalue.push(temp+1);
        }
    }
    return maxNum;
}
