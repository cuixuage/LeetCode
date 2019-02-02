/*
已排序的链表 删除重复的元素
我加上了删除节点空间的代码语句   位置1在leetcode上可以AC 但是在牛客网上无法AC
*/

#include "func.h"
ListNode* deleteDuplicates(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* pre = new ListNode(0);
    ListNode* ans = pre;
    pre->next = head;
    head = head->next;
    while(head!=NULL){
        if(pre->next->val == head->val){
            //delete pre->next;           //1.
            pre->next = head;
        }
        else
            pre = pre->next;
        head = head->next;
    }
    ListNode* res = ans->next;
    delete ans;
    return res; 
} 