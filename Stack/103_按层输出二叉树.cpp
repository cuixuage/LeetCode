/*
二维数组保存来保存整个树结构 vector<vector<int> >
在每一层再判断level%2 => 正序/倒序插入数据
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
注:改进使用deque 前端、后端快速插入删除
*/

//root->left->right 遍历顺序 (只不过用level标识)
//只不过每一层级插入的顺序不同 选择相应level很关键
void traval(TreeNode* curr,vector<vector<int>>& answer,int level){    //要传入实参&
    if(curr == NULL) return ;
    if(answer.size()<=level){
        vector<int> temp ;
        answer.push_back(temp);
    }
    vector<int> collection =answer[level];  //关键 选择相应的level
    if(level%2==0) collection.push_back(curr->val);
    else collection.insert(collection.begin(),curr->val);
    answer[level] = collection;             //更新answer层级

    traval(curr->left,answer,level+1);
    traval(curr->right,answer,level+1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> answer;
    traval(root,answer,0);
    return answer;
}



