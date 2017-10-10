/*升序排序的链表转化为BST binary search tree 二叉搜索树
    递归处理左右子树
*/

#include <stdio.h>
#include <iostream>
using std::endl;
using std::cout;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
public:
    TreeNode *sortedListToBST(ListNode *head){
        if(head==NULL) return NULL;
        return sortedListToBST(head,NULL);   //函数重载
    }
private:
    TreeNode *sortedListToBST(ListNode *head,ListNode *tail){
        if(head==tail) return NULL;
        if(head->next==tail){
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *slow = head,*fast=head;
        //寻找中间位置结点 tail是尾部指针
        while(fast!=tail && fast->next!= tail){   //偶数元素时slow指向后半段第一个元素
        //while(fast->next!=tail && fast->next->next!= tail) Accepted 如此构建BST也被允许
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head,slow);
        root->right = sortedListToBST(slow->next,tail);
        return root;
    }
};

int main(int argc,char** argv){

}
