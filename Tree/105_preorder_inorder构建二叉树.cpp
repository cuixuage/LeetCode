    /*对比144 145 94 */
//通过前序遍历 中序遍历获取二叉树
//更进一步   得到二叉树后输出后序遍历

//思路: 递归preorder第一个节点为根节点 从inorder中寻找其root
//假设所有节点中没有重复val值

TreeNode* buildTree(vector<int> & preorder,vector<int> inorder){
    return helper(0,0,inorder.size()-1,preorder,inorder);
}

/*
参数:当前子树root节点位置(preorder中寻找)
     当前子树所有元素的起始、终点位置
     preorder inorder数组
*/
TreeNode* helper(int prestart,int instart, int inend, vector<int>& preorder, vector<int>& inorder){
    if(prestart > preorder.size()-1 || instart > inend)
        return NULL;
    TreeNode* root = new TreeNode(preorder[prestart]);      //root所在preorder
    int idx=0;                                             //当前子树的root节点所在inorder序号
    for(int i=instart;i<=inend;i++)                        //小于等于
        if(inorder[i] == root->val)
            idx = i;
    //左子树
    root->left = helper(prestart+1,instart,idx-1,preorder,inorder);
    //右子树
    root->right = helper(prestart+idx-instart+1,idx+1,inend,preorder,inorder);
    //注意右子树的root节点位置

    return root;
}
