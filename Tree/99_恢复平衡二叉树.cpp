#include "func.h"
/*
binary search二分查找树中两个元素被错误地交换了
恢复原有的平衡性
思路:
1. 二插查找树的 中序遍历 是有序的,那么只需要找出"无序"的两个元素
2. 而且只需要swap value即可
*/
/*
注释:  前序遍历的递归写法
traverse(root.left)
//Do something
// print(root.value)   这里会顺序输出中序遍历值  
traverse(root.right)
*/

class Solution{
public:
    void recoverTree(TreeNode* root){
        traverse(root);
        std::swap(first->val,second->val);
    }
private:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* preElement = new TreeNode(INT_MIN);       //最好还是不要依赖INT_MIN INT_MAX
    void traverse(TreeNode*root){
        if (root==NULL) return;
        traverse(root->left);
        //start 中序遍历
        //e.g.  1 3 2 4找出对应的first second
        
        if(first == NULL && preElement->val >= root->val)
            first = preElement;
        if(first != NULL && preElement->val >= root->val)       //first=3 second=2
            second = root;
        preElement = root;
        
        //end 中序遍历
        traverse(root->right);
    }
}
