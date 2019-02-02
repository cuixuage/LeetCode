/*
已排序的链表 将出现重复的元素全部删除 一个也不保留
思路1:
1.head不断移动直到到达下一个非重复元素的位置
2.哨兵节点需要判断两种情况
2.1 [pre->next，head) 没有重复元素
2.2 [pre->next，head) 之间即为重复元素
*/
#include "func.h"

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



//***************原来的代码
ListNode *deleteDuplicates(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode *pre = new ListNode(0);
    pre->next = head;
    ListNode *temp=pre;
    while(head!=NULL){
        //找到重复元素的最后一个
        while(head->next!=NULL && head->val == head->next->val)  head = head->next;
        //更新pre位置——停留在重复元素的pre位置
        if(pre->next==head) pre = pre->next;
        //指向重复元素的next位置
        else pre->next=head->next;
        head = head->next;
    }
    return temp->next;
}