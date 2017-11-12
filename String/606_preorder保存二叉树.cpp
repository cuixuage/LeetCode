/* 给定TreeNode* root 按照preorder格式遍历*/

//思路1: preorder——递归解决
//思路2: preorder while(!stack.empty) 判断stack.top是否visted

#include "func.h"

//递归
string tree2str(TreeNode* t)
{
    if(t==NULL) return "";
    if(t->left==NULL && t->right==NULL) return to_string(t->val);  //整数转字符串
    //左子树不为空,右子树为空时
    else if(t->right==NULL)
        return to_string(t->val)+"("+tree2str(t->left)+")";
    //左子树为空,右子树不为空  or  左右子树都不为空时
    return to_string(t->val)+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")";

}

//****************stack   对比stack那几个二叉树的题目
string tree2str(TreeNode* t)
{
    if(t==NULL) return "";
    stack<TreeNode*> mystack;
    mystack.push(t);
    set<TreeNode*> visited;
    string s;
    while(!mystack.empty())
    {
        t=mystack.top();
        if(t!=NULL && visited.count(t))
        {
            mystack.pop();
            s +=")";
        }
        else if(t!=NULL)
        {
            visited.insert(t);
            s += "(" + to_string(t->val);
            if (t->left == nullptr && t->right != nullptr)   // ()只是相当于占位符  可以换成任意字符只是保证preorder不出现二义性
                s+="()";
            if (t->right != nullptr)                      //思考: 使用if 不用else if  ——不断left是否存在 right都需要加入stack,在 left之前
                mystack.push(t->right);
            if (t->left != nullptr)
                mystack.push(t->left);
            /*
            //超时？？？？
            if(t->left!=NULL && t->right!=NULL){
                mystack.push(t->right);        //preorder遍历  注意stack.push顺序
                mystack.push(t->left);
            }
            else if(t->right!=NULL){
                s +="()";
                mystack.push(t->right);
            }
            else if(t->left!=NULL)
                mystack.push(t->right);
            */
        }
    }
    return s.substr(1,s.length()-2);   //substr(m,n) => 序号[m,m+n]子串
}


//递归2    注意到string变量每次递归都会重新出现
string tree2str(TreeNode* t)
{
    if (t == NULL) return "";
    string s = to_string(t->val);
    if (t->left) s += '(' + tree2str(t->left) + ')';
    else if (t->right) s += "()";
    if (t->right) s += '(' + tree2str(t->right) + ')';
    return s;
}
