/*
出现重复的元素全部被删除
*/

#include "func.h"
 
//方式1 
ListNode* deleteDuplicates(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* tmp = pre;
    head = head->next;
    while(head!=NULL){
        if(pre->next->val == head->val) head = head->next;
        else if(pre->next->next != head){
            pre->next = head;
            head = head->next;
        }else{
            pre = pre->next;
            head = head->next;
        }
    }
    //e.g. {1,1,1}链表需要返回NULL
    if(pre->next!=NULL && pre->next->next!=head) pre->next = NULL;
    return tmp->next;
}

//方式2   更推荐
ListNode* deleteDuplicates(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* pre = new ListNode(0);
    ListNode* pretmp = pre;
    pre->next = head;
    head = head->next;
    while(head!=NULL){
        while(head!=NULL && pre->next->val == head->val) //1.
            head = head->next;
        if(head==NULL){ pre->next = NULL; break; }

        if(pre->next->next == head)//2.1
            pre = pre->next;
        else   //2.2
            pre->next = head;
        head = head->next;
    }
    ListNode* ans = pretmp->next;
    delete pretmp;
    return ans;
}