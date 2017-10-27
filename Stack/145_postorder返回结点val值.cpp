/*
按照postorder前序遍历返回每一个节点的val
For example:
参数传递是treeNode* root 对比144preorder
  1
    \
     2
    /
   3
return [3,2,1]    left-》right-》root
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

//方法1 转置preorder (但是preorder要求是root->right->left格式  =》 left->right->root符合要求)
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack;
    myStack.push(root);
    while(!myStack.empty())
    {
        TreeNode* node = myStack.top();
        myStack.pop();
        if(node!=nullptr)               //更改preorder为root->right->left格式
        {
            result.push_back(node->val);
            myStack.push(node->left);
            myStack.push(node->right);
        }
    }
    std::reverse(result.begin(),result.end());   //转置
    return result;
}
//方法2 转置preorder
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> myStack ;
    TreeNode* node = root;
    while(!myStack.empty() || node != nullptr)
    {
        if(node != nullptr)
        {
            myStack.push(node);             //新的root结点加入stack
            result.push_back(node->val);
            node = node->right;             //root->right->left 转置为 left->right->root
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

