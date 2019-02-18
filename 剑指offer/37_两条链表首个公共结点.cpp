/*
思路:
A,B两条链表差值是diff,fast链表先走diff 直到slow和fast相遇
*/

#include "func.h"
ListNode* getIntersectionNode(ListNode* A, ListNode* B){
    ListNode* p1 = A;
    ListNode* p2 = B;
    if(p1==NULL || p2==NULL) return NULL;
    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
        if(p1==p2) return p1;
        //1.
        if(p1==NULL) p1 = B;
        if(p2==NULL) p2 = A;
    }
    //2.
    return p1;
}
//note: 2.可能A,B没有公共节点 此时p1==p2==NULL

//方法2: 链表长的先移动一定步数
int getLength(ListNode* head){
    int len = 0;
    ListNode* tmp = head;
    while(tmp!=NULL){
        len++;
        tmp = tmp->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    int La = getLength(headA);
    int Lb = getLength(headB);
    ListNode* longhead = headA;
    ListNode* shorthead = headB;
    int diff = std::abs(La - Lb);
    if(Lb > La){
        longhead = headB;
        shorthead = headA;
    }
    while(diff--){          //长链表先移动diff步
        longhead = longhead->next;
    }

    while(longhead!=NULL && shorthead!=NULL && longhead!=shorthead){
        longhead = longhead->next;
        shorthead = shorthead->next;
    }
    return longhead;
}