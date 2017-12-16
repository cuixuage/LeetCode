/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //�Ա� 107 ��Ҫansת��
    //DFS   һ��ͨ�� 
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;            //�������մ�
//         levelMaker(ans,root,0);
//         return ans;
//     }
// private:
//     void levelMaker(vector<vector<int>> &ans,TreeNode* curr,int level){     //level��0��ʼ
//         if (curr==NULL) return ;
//         if(level == ans.size()){
//             vector<int> temp;
//             ans.push_back(temp);
//         }
//         ans[level].push_back(curr->val);
//         levelMaker(ans,curr->left,level+1);
//         levelMaker(ans,curr->right,level+1);
//     }
    
    //BFS
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*> myqueue;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        myqueue.push(root);
        while(!myqueue.empty()){
            int levelNum = myqueue.size();           //�õ���ǰlevel�����д�����Ԫ�ظ�����
            vector<int> token;
            for(int i=0;i<levelNum;i++){                //levelNum  ���ﲻ�ܻ���myqueue.size  ��Ϊÿ��ѭ��size��С����仯
                TreeNode* curr = myqueue.front();
                if(curr->left)
                    myqueue.push(curr->left);
                if(curr->right)
                    myqueue.push(curr->right);
                
                token.push_back(curr->val);
                myqueue.pop();
            }
            ans.push_back(token);
        }
        return ans;
    }
};