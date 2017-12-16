/*对比 103题*/

//1.DFS  (传递当前层级序号)
//直接使用二维数组保存结果 level记录当前结点所在的层级
    vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> ans;
    levelMaker(ans,root,0);
    std::reverse(ans.begin(),ans.end());  //这是将vector<int>也是迭代器了？reverse iterator
    return ans;
}

void levelMaker(vector<vector<int>> &ans,TreeNode* curr,int level)
{
    if(curr == NULL) return ;
    if(ans.size()==level)                               //或者小于等于
    {
        vector<int> temp;
        ans.push_back(temp);
    }
    // vector<int> collection = ans[ans.size()-level-1];
    // collection.push_back(curr->val);
    // ans[ans.size()-level-1] = collection;
    ans[level].push_back(curr->val);

    levelMaker(ans,curr->left,level+1);                 //level是当前层级序号
    levelMaker(ans,curr->right,level+1);


}

//BFS  queue
vector<vector<int>> levelOrderBottom_2(TreeNode* root)
{
    queue<TreeNode*> myqueue;
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    myqueue.push(root);
    while(!myqueue.empty())
    {
        int cur_levelnum = myqueue.size();          //levelnum 是当前层次所包含的所有元素个数             //myqueue
        vector<int> collection;
        for(int i=0; i<cur_levelnum; i++)
        {
            TreeNode* cur = myqueue.front();
            if(cur->left != NULL)
                myqueue.push(cur->left);
            if(cur->right!=NULL)
                myqueue.push(cur->right);

            collection.push_back(cur->val);
            myqueue.pop();
        }
        ans.insert(ans.begin(),collection);                 //从头部insert  ||  或者reverse ans
    }
    return ans;
}
