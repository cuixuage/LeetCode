/*
删除链表的倒数第k个元素（k是有效值） one-pass
思路:
快慢指针  间隔为k
*/

#include "func.h"
ListNode* removeNthFromEnd(ListNode* head,int n){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && n--)
        fast = fast->next;
    if(fast==NULL)  return head->next;      //关键:  当N==链表长度时,删除头结点
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    //slow节点是待删除节点的哨兵节点
    slow->next = slow->next->next;
    return head;
}