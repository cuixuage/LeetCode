 /*
 从倒数第k个的节点 放置在链表最前 k可能大于链表长度
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
思路1:
slow fast指针间隔为k%length,寻找到分割点
思路2:
分割点为 length-k%length位置，切割链表重新拼接即可
*/

#include "func.h"
ListNode* rotateRight(ListNode* head,int k){
    if(head==NULL || head->next==NULL) return head;
    ListNode* headtmp = head;
    int len = 0;
    while(headtmp!=NULL){
        headtmp = headtmp->next;
        len ++;
    }
    headtmp = head;
    //寻找切割点的 pre节点
    k = len - k%len;
    for(int i=0;i<k-1;i++)
        headtmp = headtmp->next;
    ListNode* newHead = headtmp->next;
    headtmp->next = NULL;
    //重新拼接
    if(newHead==NULL) return head;      //相当于k==len||k==0 不旋转
    ListNode* newHeadtmp = newHead;
    while(newHeadtmp->next != NULL)
        newHeadtmp = newHeadtmp->next;
    newHeadtmp->next = head;

    return newHead;
}

/*
重新拼接的trick  将原来链表构建成环 再切割点出分割
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
*/