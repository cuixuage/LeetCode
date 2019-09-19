/*
升序的链表转化为二分查找树(自平衡的 left<root<right)
关键idea：
二分查找方式寻找root节点

区分TreeNode 和 ListNode两种类型
*/

#include "func.h"
class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head){
        if(head == NULL) return NULL;
        return sortedListToBST(head,NULL);
    }
private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;

        //1. 返回条件:  new节点
        if(head->next == tail){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }

        //2. 递归左右子树 
        ListNode* slow=head,*fast = head;
        while(fast!=tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head,slow);
        root->right = sortedListToBST(slow->next,tail);
        return root;
    }
};
}