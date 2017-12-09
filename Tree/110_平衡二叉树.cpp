/*�ж�һ���������Ƿ��Ǹ߶�ƽ��� ���������߶Ȳ����1*/

//˼·1: ���϶��·��� O(n^2) ���������ж�ÿһ��������������ƽ��&&�߶Ȳ����1
int depth(TreeNode* root){
    if(root==NULL) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

bool isBalanced (TreeNode* root){
    if(root==NULL) return true;
    int left=depth(root->left);
    int right=depth(root->right);
    return abs(left-right)<=1 && isBalanced(root->left)
                            && isBalanced(root->right);
}

//���¶���  O(N)
//����DFS,�ݹ��з��ص�ǰ���߶�
int dfsHeight(TreeNode* root){
    if(root == NULL) return 0;
    int leftHeight=dfsHeight(root->left);           //DFS ����
    if(leftHeight ==-1) return -1;
    int rightHeight=dfsHeight(root->right);
    if(rightHeight==-1) return -1;

    if(abs(leftHeight-rightHeight)>1) return -1;
    return max(leftHeight,rightHeight)+1;       //�ؼ� ���ص�ǰ�ڵ�ĸ߶�
}

bool isBalanced(TreeNode* root){
    return dfsHeight(root) != -1;
}
