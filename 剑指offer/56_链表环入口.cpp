/*
思路核心:
fast指针和slow指针相遇时,距离关系fast=2*slow
推导得: L1 = (n-1)*C + C-L2
1.记录fast slow相遇点meet
2.meet和初始head同时同速移动,再相遇点即为环的入口节点
*/

#include "func.h"
ListNode* EntryNodeOfLoop(ListNode* head){
    ListNode* meet = getMeetNode(head);
    if(meet == NULL) return NULL;
    ListNode* entry = head;
    while(entry != meet){
        meet = meet->next;
        entry = entry->next;
    }
    return entry;
} 

//如果存在环 返回meet节点
ListNode* getMeetNode(ListNode* head){
    if(head==NULL) return NULL;
    ListNode* fast=head,*slow = head;       
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return fast;
    }
    return NULL;
}

//note:  fast和slow必须同一起点,否则公式不成立
//比如我喜欢 将fast初始值设置为fast->next 