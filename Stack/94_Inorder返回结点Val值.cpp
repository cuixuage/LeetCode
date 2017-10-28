vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> rootStack;
    vector<int> inorder;
    TreeNode* p = root;
    while(!rootStack.empty() || p!=nullptr){
        if(p!=nullptr){
            rootStack.push(p);
            p=p->left;
        }
        else{
            TreeNode* node = rootStack.top();
            rootStack.pop();
            inorder.push_back(node->val);  //������left������stack��
            p = node->right;
        }
    }
    return inorder;
}
