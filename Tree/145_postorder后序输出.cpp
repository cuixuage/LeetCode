/*144��preorder 94��inorder 103�ⰴ�����*/

#include"func.h"
vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> mystack;  //�������д��������
    mystack.push(root);

    while(!mystack.empty()){
        TreeNode* node = mystack.top();
        mystack.pop();              //�Ӵ�������㼯����ɾ���˽ڵ�
        if(node!=NULL){
            result.push_back(node->val);
            mystack.push(node->left);   //ע��stack��ջ��ջ˳��
            mystack.push(node->right);
        }
    }
    std::reverse(result.begin(),result.end());//���left->right->root˳��
    return result;
}
