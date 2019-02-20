/*
归并两个单调链表,仍然单调递增
*/
#include "func.h"
ListNode* merge(ListNode* A, ListNode* B){
    ListNode* pre = new ListNode(0);
    ListNode* pretmp = pre;
    while(A && B){
        if(A->val < B->val){
            pre->next = A;
            pre = pre->next;
            A = A->next;
        }else{
            pre->next = B;
            pre = pre->next;
            B = B->next;
        }
    }
    pre->next = A==NULL?B:A;        //trick 要会
    //delete
    return pretmp->next;
}

//A==NULL?pre->next=B:pre->next=A;       //错误写法 