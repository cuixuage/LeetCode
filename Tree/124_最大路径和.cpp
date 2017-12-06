/*����Ҫͨ��root,����һ�����,������·����*/

//�Ա�129�� ˼·����
//1.ȫ�ֱ����������ս��(������ÿһ�εݹ����޸�)
//��ò�Ҫʹ��ȫ�ֱ���

#include"func.h"

public:
int maxPathSum(TreeNode* root){
    int maxvalue = INT_MIN;
    maxPathDown(root,maxvalue);         //����ó��Լ���
    return maxvalue;
}
private:
int maxPathDown(TreeNode* node, int& maxvalue){
    if(node==NULL) return 0;
    int left= std::max(0,maxPathDown(node->left,maxvalue));        //�����������·��
    int right = std::max(0,maxPathDown(node->right,maxvalue));
    maxvalue = std::max(maxvalue,left+right+node->val); //�����κ�һ��node�����˵,��֮�µ��·��=left����+right����+����->val
    return std::max(left,right)+node->val;              //���ص���node(���ڵ�,�����ڵ���)���·��
}

/*ȫ�ֱ���
    int maxvalue;
int maxPathSum(TreeNode* root){
    maxvalue = INT_MIN;
    maxPathDown(root);
    return maxvalue;
}

int maxPathDown(TreeNode* node){
    if(node==NULL) return 0;
    int left=std::max(0,maxPathDown(node->left));        //�����������·��
    int right = std::max(0,maxPathDown(node->right));
    maxvalue = std::max(maxvalue,left+right+node->val);
    return std::max(left,right)+node->val;               //�����κ�һ��node�����˵,��֮�µ��·��=left����+right����+����->val
}
*/
