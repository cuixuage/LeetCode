/* ����TreeNode* root ����preorder��ʽ����*/

//˼·1: preorder�����ݹ���
//˼·2: preorder while(!stack.empty) �ж�stack.top�Ƿ�visted

#include "func.h"

//�ݹ�
string tree2str(TreeNode* t)
{
    if(t==NULL) return "";
    if(t->left==NULL && t->right==NULL) return to_string(t->val);  //����ת�ַ���
    //��������Ϊ��,������Ϊ��ʱ
    else if(t->right==NULL)
        return to_string(t->val)+"("+tree2str(t->left)+")";
    //������Ϊ��,��������Ϊ��  or  ������������Ϊ��ʱ
    return to_string(t->val)+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")";

}

//****************stack   �Ա�stack�Ǽ�������������Ŀ
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
            if (t->left == nullptr && t->right != nullptr)   // ()ֻ���൱��ռλ��  ���Ի��������ַ�ֻ�Ǳ�֤preorder�����ֶ�����
                s+="()";
            if (t->right != nullptr)                      //˼��: ʹ��if ����else if  ��������left�Ƿ���� right����Ҫ����stack,�� left֮ǰ
                mystack.push(t->right);
            if (t->left != nullptr)
                mystack.push(t->left);
            /*
            //��ʱ��������
            if(t->left!=NULL && t->right!=NULL){
                mystack.push(t->right);        //preorder����  ע��stack.push˳��
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
    return s.substr(1,s.length()-2);   //substr(m,n) => ���[m,m+n]�Ӵ�
}


//�ݹ�2    ע�⵽string����ÿ�εݹ鶼�����³���
string tree2str(TreeNode* t)
{
    if (t == NULL) return "";
    string s = to_string(t->val);
    if (t->left) s += '(' + tree2str(t->left) + ')';
    else if (t->right) s += "()";
    if (t->right) s += '(' + tree2str(t->right) + ')';
    return s;
}
