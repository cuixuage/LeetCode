/*判断一个二叉树是否是高度平衡的 左右子树高度差不超过1*/

//思路1: 自上而下方法 O(n^2) 从上至下判断每一个结点的左右子树平衡&&高度差不超过1
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

//自下而上  O(N)
//基于DFS,递归中返回当前结点高度
int dfsHeight(TreeNode* root){
    if(root == NULL) return 0;
    int leftHeight=dfsHeight(root->left);           //DFS 回溯
    if(leftHeight ==-1) return -1;
    int rightHeight=dfsHeight(root->right);
    if(rightHeight==-1) return -1;

    if(abs(leftHeight-rightHeight)>1) return -1;
    return max(leftHeight,rightHeight)+1;       //关键 返回当前节点的高度
}

bool isBalanced(TreeNode* root){
    return dfsHeight(root) != -1;
}
