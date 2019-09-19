/*���� root��leaf֮�͵���sum ��·���ڵ�����*/
//˼·: DFS(����Ļ�������) �Ա�112��
//ע��: DFS ��ϸ���� �ݹ�ʱ���ص�˳�� �Լ� path.pop()λ��

//记录路径和==target路径

public:
vector<vector<int>> pathSum(TreeNode* root,int sum){
    vector<vector<int>> ans;
    vector<int> path;
    findPaths(root,sum,path,ans);  //��������
    return ans;
}
private:
void findPaths(TreeNode* node,int sum,vector<int>& path,vector<vector<int>>& ans){
    if(!node) return;
    path.push_back(node->val);
    if(!(node->left) && !(node->right)&& sum==node->val)
        ans.push_back(path);
        //��ϸ˼�����ݣ�DFS������ν�������
    findPaths(node->left,sum-node->val,path,ans);
    findPaths(node->right,sum-node->val,path,ans);
    //ע��pop_back��λ��
    path.pop_back();
}
};
