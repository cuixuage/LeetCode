/*
两个已排序的链表 merge
关键idea:
while循环的判断条件 l1!=NULL && l2!=NULL
*/

#include "func.h"

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    ListNode* pre = new ListNode(0);
    ListNode* pretmp = pre;
    while(l1!=NULL && l2!=NULL){        //关键
        if(l1->val <= l2->val){
            pre->next = l1;
            l1 = l1->next;
        }else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if(l1 == NULL) pre->next = l2;
    else pre->next = l1;
    // pre->next = l1==NULL?l2:l1;
    ListNode* ans = pretmp->next;
    delete pretmp;
    return ans;
}