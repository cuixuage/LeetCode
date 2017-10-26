/*
iterator �����������з��ض��ֲ���������Ԫ��
����:  ��ͼ��ʾ������  (stack ����˳��: push10 5 hasnext��pop5 push8 6)
       10
     5    12
       8
     6
��ʼ��: pushNodes root��������left���
hasnext:stack.top()һֱ�ǵ�ǰ��С + ��ʱtop()����Ȼû��left�����
*/

#include<iostream>
using std::cout;
using std::endl;
//  iteratorҪ��:
//  BSTIterator i = BSTIterator(root);
//  while (i.hasNext()) cout << i.next();
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> MyStack;         //treeNodeָ��
private:
    void pushNodes(TreeNode* node){
        for(;node!=NULL;node=node->left)
            MyStack.push(node);
    }
public:
    BSTIterator(TreeNode *root) {     //���캯��
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
        pushNodes(temp->right);   //**********�ؼ�
        //ע:��temp����������������ѹ��ջ
        //����������������ζ��temp��Ϊroot��������������������
        return temp->val;
    }
};
