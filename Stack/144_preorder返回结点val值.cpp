/*
按照preorder前序遍历返回每一个节点的val
For example:
参数传递是treeNode* root 对比331题判断{1,#,2,3,#}是否能构建二叉树
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
按照preorder前序遍历返回每一个节点的val
For example:
参数传递是treeNode* root 对比331题判断{1,#,2,3,#}是否能构建二叉树
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
    stack<TreeNode*> myStack;    //保存根左右遍历顺序  保存preorder遍历的结点
    myStack.push(root);          //initialize
    while(!myStack.empty()){
        TreeNode* node = myStack.top();
        myStack.pop();
        if(node!=nullptr){              //myStack也被push了NULL结点  需要判断
            result.push_back(node->val);
            myStack.push(node->right);
            myStack.push(node->left);
        }
    }
    return result;
}

