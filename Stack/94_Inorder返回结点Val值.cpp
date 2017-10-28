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
            inorder.push_back(node->val);  //在所有left结点加入stack后
            p = node->right;
        }
    }
    return inorder;
}
