/*
����postorderǰ���������ÿһ���ڵ��val
For example:
����������treeNode* root �Ա�144preorder
  1
    \
     2
    /
   3
return [3,2,1]    left-��right-��root
*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<deque>
#include<cstdlib>
#include<algorithm>
using std::endl;
using std::cout;
using std::vector;
using std::deque;
using std::string;
using std::stack;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//����1 ת��preorder (����preorderҪ����root->right->left��ʽ  =�� left->right->root����Ҫ��)
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack;
    myStack.push(root);
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top();
        myStack.pop();
        if(node!=nullptr)               //����preorderΪroot->right->left��ʽ
        {
            result.push_back(node->val);
            myStack.push(node->left);
            myStack.push(node->right);
        }
    }
    std::reverse(result.begin(),result.end());   //ת��
    return result;
}
//����2 ת��preorder
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack ;
    TreeNode* node = root;
    while(!myStack.empty() || node != nullptr)
    {
        if(node != nullptr)
        {
            myStack.push(node);             //�µ�root������stack
            result.push_back(node->val);
            node = node->right;             //root->right->left ת��Ϊ left->right->root
        }
        else
        {
            TreeNode* temp = myStack.top();
            myStack.pop();
            node = temp->left;
        }
    }
    std::reverse(result.begin(),result.end());
    return result;
}

