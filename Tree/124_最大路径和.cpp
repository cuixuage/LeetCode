/*不需要通过root,至少一个结点,求最大的路径和*/

//对比129题 思路类似
//1.全局变量保存最终结果(方便在每一次递归中修改)
//最好不要使用全局变量

#include"func.h"

public:
int maxPathSum(TreeNode* root){
    int maxvalue = INT_MIN;
    maxPathDown(root,maxvalue);         //别调用成自己了
    return maxvalue;
}
private:
int maxPathDown(TreeNode* node, int& maxvalue){
    if(node==NULL) return 0;
    int left= std::max(0,maxPathDown(node->left,maxvalue));        //左子树中最长的路径
    int right = std::max(0,maxPathDown(node->right,maxvalue));
    maxvalue = std::max(maxvalue,left+right+node->val); //对于任何一个node结点来说,它之下的最长路径=left子树+right子树+自身->val
    return std::max(left,right)+node->val;              //返回到达node(父节点,来自于单侧)的最长路径
}

/*全局变量
    int maxvalue;
int maxPathSum(TreeNode* root){
    maxvalue = INT_MIN;
    maxPathDown(root);
    return maxvalue;
}

int maxPathDown(TreeNode* node){
    if(node==NULL) return 0;
    int left=std::max(0,maxPathDown(node->left));        //左子树中最长的路径
    int right = std::max(0,maxPathDown(node->right));
    maxvalue = std::max(maxvalue,left+right+node->val);
    return std::max(left,right)+node->val;               //对于任何一个node结点来说,它之下的最长路径=left子树+right子树+自身->val
}
*/
