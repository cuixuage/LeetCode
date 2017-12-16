/*�Ա� 103��*/

//1.DFS  (���ݵ�ǰ�㼶���)
//ֱ��ʹ�ö�ά���鱣���� level��¼��ǰ������ڵĲ㼶
    vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> ans;
    levelMaker(ans,root,0);
    std::reverse(ans.begin(),ans.end());  //���ǽ�vector<int>Ҳ�ǵ������ˣ�reverse iterator
    return ans;
}

void levelMaker(vector<vector<int>> &ans,TreeNode* curr,int level)
{
    if(curr == NULL) return ;
    if(ans.size()==level)                               //����С�ڵ���
    {
        vector<int> temp;
        ans.push_back(temp);
    }
    // vector<int> collection = ans[ans.size()-level-1];
    // collection.push_back(curr->val);
    // ans[ans.size()-level-1] = collection;
    ans[level].push_back(curr->val);

    levelMaker(ans,curr->left,level+1);                 //level�ǵ�ǰ�㼶���
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
        int cur_levelnum = myqueue.size();          //levelnum �ǵ�ǰ���������������Ԫ�ظ���             //myqueue
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
        ans.insert(ans.begin(),collection);                 //��ͷ��insert  ||  ����reverse ans
    }
    return ans;
}
