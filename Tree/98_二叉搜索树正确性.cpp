/*
思路1:
递归写法

完整思路:
先得到inorder序列(平衡二叉树的inorder必然是升序排列)
*/

//递归写法  Accept
//注:  每次递归调用的返回值会 覆盖上次递归返回值
//只有当没有任何false 覆盖  才会返回正确值
public:
    bool isValidBST(TreeNode* root){
        //只有当没有任何false 覆盖  才会返回正确值
        if(root==NULL) return true;
        if( isValidBST(root->left)==false) return false;
        //do inorder bussiness
        if(pre!=NULL &&pre->val >= root->val) return false;
        pre = root;
        
        return isValidBST(root->right);
    }
private:
    TreeNode* pre=NULL;  //尽量不要依赖INT_MIN INT_MAX

//stack 写法  Accept
bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    stack<TreeNode*> myStack;
    TreeNode* pre = NULL;
    while(root!=NULL || !myStack.empty()){
        while(root!=NULL){
            myStack.push(root);
            root = root->left;
        }
        root = myStack.top();
        myStack.pop();
        if(pre!=NULL && pre->val >= root->val) 
            return false;
        pre = root;
        root = root->right;
    }
    
    // inorder遍历完所有元素
    return true;
}
    
    
//ERROR  只考虑了当前的父节点做比较
bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    if(root->left != NULL && root->left->val >= root->val)
        return false;
    if(root->right != NULL && root->right->val <= root->val)
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}
