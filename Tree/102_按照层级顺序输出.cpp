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
    //对比 107 需要ans转置
    //DFS   一遍通过 
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;            //保存最终答案
//         levelMaker(ans,root,0);
//         return ans;
//     }
// private:
//     void levelMaker(vector<vector<int>> &ans,TreeNode* curr,int level){     //level由0开始
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
            int levelNum = myqueue.size();           //得到当前level的所有待遍历元素个数、
            vector<int> token;
            for(int i=0;i<levelNum;i++){                //levelNum  这里不能换成myqueue.size  因为每次循环size大小都会变化
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