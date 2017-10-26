/*
iterator 按照升序序列返回二分查找树所有元素
例如:  下图所示二叉树  (stack 加入顺序: push10 5 hasnext？pop5 push8 6)
       10
     5    12
       8
     6
初始化: pushNodes root及其所有left结点
hasnext:stack.top()一直是当前最小 + 此时top()结点必然没有left结点了
*/

#include<iostream>
using std::cout;
using std::endl;
//  iterator要求:
//  BSTIterator i = BSTIterator(root);
//  while (i.hasNext()) cout << i.next();
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> MyStack;         //treeNode指针
private:
    void pushNodes(TreeNode* node){
        for(;node!=NULL;node=node->left)
            MyStack.push(node);
    }
public:
    BSTIterator(TreeNode *root) {     //构造函数
        pushNodes(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return MyStack.empty() ? false:true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = MyStack.top();
        MyStack.pop();
        pushNodes(temp->right);   //**********关键
        //注:将temp的右子树当做新树压入栈
        //右子树不存在则意味着temp作为root的子树按照升序遍历完毕
        return temp->val;
    }
};
