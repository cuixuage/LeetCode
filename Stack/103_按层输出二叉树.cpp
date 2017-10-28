/*
��ά���鱣���������������ṹ vector<vector<int> >
��ÿһ�����ж�level%2 => ����/�����������
    3
   / \
  9  20
    /  \
   15   7
[
  [3],
  [20,9],
  [15,7]
]
ע:�Ľ�ʹ��deque ǰ�ˡ���˿��ٲ���ɾ��
*/

//root->left->right ����˳�� (ֻ������level��ʶ)
//ֻ����ÿһ�㼶�����˳��ͬ ѡ����Ӧlevel�ܹؼ�
void traval(TreeNode* curr,vector<vector<int>>& answer,int level){    //Ҫ����ʵ��&
    if(curr == NULL) return ;
    if(answer.size()<=level){
        vector<int> temp ;
        answer.push_back(temp);
    }
    vector<int> collection =answer[level];  //�ؼ� ѡ����Ӧ��level
    if(level%2==0) collection.push_back(curr->val);
    else collection.insert(collection.begin(),curr->val);
    answer[level] = collection;             //����answer�㼶

    traval(curr->left,answer,level+1);
    traval(curr->right,answer,level+1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> answer;
    traval(root,answer,0);
    return answer;
}



