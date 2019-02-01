/*
转置[m,n]之间的链表,首节点的序号是1
思路1:
单独取出[m,n]之间链表,对其转置,再加入原链表
思路2:
1.one-pass 哨兵节点为m-1点
2.将m,n的节点按顺序加入哨兵节点后侧即为转置
*/

#include "func.h"
ListNode* reverseBetween(ListNode* head,int m,int n){
    if(head==NULL) return NULL;
    //1. 哨兵节点
    ListNode* pre = new ListNode(0);       
    ListNode* pre_2 = pre;
    pre->next = head;
    for(int i=0;i<m-1;i++) pre = pre->next;
    /*
    2. start是序号m的节点 不断将then加入pre后侧
    对于每一轮来说,then插入pre，pre->next之间
    then的前置节点是哨兵节点, then->next指向节点是pre->next节点
    */
    ListNode* start = pre->next;
    ListNode* then = start->next;  
    for(int i=m;i<n;i++){
        start->next = then->next;
        then->next = start;
        pre->next = then;
        then = start->next; 
    }
    ListNode* ans = pre_2->next;
    delete pre_2;
    return ans;
}