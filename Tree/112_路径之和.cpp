/*easy: ���������� ��������root->leaf��·����
�ж�����·��sum֮��  �Ƿ���ں͸���sum��ȵ�·��*/

//�ǵݹ�  (queue������BFS)
//�Ա� DFS'113��
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
        q.pop();        //ɾ��cur�ڵ�2ȥ
    }
    return false;
}

//�ݹ�
bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;

    //�ؼ�: ��һ�ֵݹ��ж� sum-root->val
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
