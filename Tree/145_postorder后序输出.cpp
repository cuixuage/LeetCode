/*144题preorder 94题inorder 103题按层输出*/

#include"func.h"
vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> mystack;  //保存所有待遍历结点
    mystack.push(root);

    while(!mystack.empty()){
        TreeNode* node = mystack.top();
        mystack.pop();              //从待遍历结点集合中删除此节点
        if(node!=NULL){
            result.push_back(node->val);
            mystack.push(node->left);   //注意stack入栈出栈顺序
            mystack.push(node->right);
        }
    }
    std::reverse(result.begin(),result.end());//结果left->right->root顺序
    return result;
}
