
//注意题目是先给出inorder顺序 后面才是postorder
//一次 AC

//改进 每次递归中的循环可以改为hashmap
//给定 postorder中确定的root->val  O(1) 得到其对应inorder位置

TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
    return helper(postorder.size()-1,0,inorder.size()-1,postorder,inorder);
}

TreeNode* helper(int postend,int is,int ie,vector<int>& postorder,vector<int>& inorder){
    if(postend <0 || is>ie)
        return NULL;
    TreeNode* root = new TreeNode(postorder[postend]);
    int idx=0;
    for(int i=is;i<=ie;i++)
        if(inorder[i] == root->val)
            idx=i;
            //1.postorder下一层级的root位置
            //2.inorder下一层级子树的元素start end位置
    root->left = helper(postend-(ie-idx)-1,is,idx-1,postorder,inorder);
    root->right = helper(postend-1,idx+1,ie,postorder,inorder);
    return root;
}
