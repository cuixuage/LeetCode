/*最小深度是沿着从根节点到最近的叶节点的最短路径的节点的数量。
叶子节点是left==NULL && right==NULL的节点   左右子树均为NULL，则是叶子节点
只有一个根节点 return 1 */

#include "func.h"
//所有叶子结点中距离根节点最近的 && 有共同母子节点的   叶子节点个数
int minDepth(TreeNode* root){
    if(root == nullptr) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    //如果左右子树均不存在 则返回1
    return (left==0 || right==0)? left+right+1:std::min(left,right)+1;
}
int main(){

}
