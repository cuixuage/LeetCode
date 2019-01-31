#include "func.h"
/*
1.均分分割成两条链表
2.将第二条链表转置
3.归并
得到 1,n,2,n-1,3,n-2....顺序的链表
*/

class Solution{
public:
    void reorderList(ListNode* head){
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return ;
        //1.
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //2. [mid，n]均需要被转置
        ListNode *mid = reverseListNode(slow->next);
        slow->next = NULL;
        slow = head;
        head = mergeListNode(slow,mid);
    }
private:
    ListNode* reverseListNode(ListNode* head){
        ListNode* pre = NULL;       //不使用new 不会开辟空间
        ListNode* next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    ListNode* mergeListNode(ListNode* p1,ListNode* p2){
        // p2后半部分链表长度小于p1
        ListNode* head = p1;
        ListNode* tmp1 = NULL;
        ListNode* tmp2 = NULL;
        while(p2 != NULL){
            tmp1 = p1->next;
            tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
        return head;
    }
    /*
        ListNode* mergeListNode(ListNode* p1,ListNode* p2){
            // 方式二
            ListNode* head = p1;
            ListNode* tmp = NULL;
            while(p2 != NULL){
                tmp = p2->next;
                p2->next = p1->next;
                p1->next = p2;      //p1和p1->next之间插入p2
                p1 = p2->next;
                p2 = tmp;
            }
            return head;
        }
    */
}