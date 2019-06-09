//树的路径和 删除不满足limit的节点

void hasPathSum(TreeNode* root, int limit){
    if(root==NULL) return root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
        //到达叶子节点
        if(!top->left && !top->right && top->val <= limit) top=NULL;
        if(top->left){
            top->left->val += top->val;
            q.push(top->left);
        }
        if(top->right){
            top->right->val += top->val;
            q.push(top->right);
        }
    }
}