/*��С��������ŴӸ��ڵ㵽�����Ҷ�ڵ�����·���Ľڵ��������
Ҷ�ӽڵ���left==NULL && right==NULL�Ľڵ�   ����������ΪNULL������Ҷ�ӽڵ�
ֻ��һ�����ڵ� return 1 */

#include "func.h"
//����Ҷ�ӽ���о�����ڵ������ && �й�ͬĸ�ӽڵ��   Ҷ�ӽڵ����
int minDepth(TreeNode* root){
    if(root == nullptr) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    //������������������� �򷵻�1
    return (left==0 || right==0)? left+right+1:std::min(left,right)+1;
}
int main(){

}
