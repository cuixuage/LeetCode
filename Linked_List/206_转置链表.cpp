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

//递归版本的链表转置  画图理解
ListNode* reverseList(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    return reverseList(NULL,head);          //参数 pre节点,cur节点
}
ListNode* reverseList(ListNode* pre, ListNode* cur){
    if(cur==NULL) return pre;
    ListNode* next = cur->next;
    cur->next = pre;
    return reverseList(cur,next);
}