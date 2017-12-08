/*easy: 给定二叉树 保存所有root->leaf的路径和
判断所有路径sum之中  是否存在和给定sum相等的路径*/

//非递归  (queue类似于BFS)
//对比 DFS'113题
bool hasPathSum(){
    queue<TreeNode*> q;
    if(root!=NULL) q.push(root);

    while(!q.empty()){
        TreeNode* cur = q.front();
        if(cur->left==NULL && cur->right==NULL){
            if(cur->val==sum) return true;
        }
        if(cur->left!=NULL){
            cur->left->val +=cur->val;
            q.push(cur->left);
        }
        if(cur->right!=NULL){
            cur->right->val +=cur->val;
            q.push(cur->right);
        }
        q.pop();        //删除cur节点2去
    }
    return false;
}

//递归
bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;

    //关键: 下一轮递归判断 sum-root->val
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
