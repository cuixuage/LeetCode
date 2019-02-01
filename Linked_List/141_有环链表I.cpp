#include"func.h"
/*
判断链表是否有环
快慢指针
*/

bool hasCycle(ListNode* head){
    if(head==NULL || head->next==NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        if(fast == slow) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}