#include "func.h"
/*
转置链表思路
1.哨兵节点pre
2.更新pre head
*/
ListNode* reverseList(ListNode* head){
    ListNode* pre = NULL;
    while(head!=NULL){
        ListNode* tmp = head->next;
        head->next = pre;
        pre = head;         //更新pre,head
        head = tmp;
    }
    return pre;
}