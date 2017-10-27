/*
����preorderǰ���������ÿһ���ڵ��val
For example:
����������treeNode* root �Ա�331���ж�{1,#,2,3,#}�Ƿ��ܹ���������
   1
    \
     2
    /
   3
return [1,2,3]
*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cstdlib>
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::stack;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root){
/*
����preorderǰ���������ÿһ���ڵ��val
For example:
����������treeNode* root �Ա�331���ж�{1,#,2,3,#}�Ƿ��ܹ���������
   1
    \
     2
    /
   3
return [1,2,3]
*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cstdlib>
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::stack;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> myStack;    //��������ұ���˳��  ����preorder�����Ľ��
    myStack.push(root);          //initialize
    while(!myStack.empty()){
        TreeNode* node = myStack.top();
        myStack.pop();
        if(node!=nullptr){              //myStackҲ��push��NULL���  ��Ҫ�ж�
            result.push_back(node->val);
            myStack.push(node->right);
            myStack.push(node->left);
        }
    }
    return result;
}

