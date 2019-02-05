/*
两个链表相加
*/
#include "func.h"
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    int carray = 0;
    ListNode* pre = new ListNode(0);
    ListNode* pretmp = pre;
    while(l1&&l2){
        int sum = l1->val+l2->val+carray;
        ListNode* tmp = new ListNode(sum%10);
        carray = sum/10;
        pre->next = tmp;
        pre = pre->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1==NULL){
        while(l2!=NULL){
            int sum=l2->val + carray;
            if(sum>=10) carray=1;
            else carray=0;
            ListNode* temp=new ListNode(sum%10);
            pre->next = temp;
            pre = pre->next;
            l2=l2->next;
        }
        //如果最后l1 l2均为NULL后仍进位1 仍需新建结点
        if(carray==1) {
            ListNode* temp=new ListNode(1);
            pre->next = temp;
            pre = pre->next;
        }
    }
    else if(l2==NULL){
        while(l1!=NULL){
            int sum=l1->val + carray;
            if(sum>=10) carray=1;
            else carray=0;
            ListNode* temp=new ListNode(sum%10);
            pre->next = temp;
            pre = pre->next;
            l1=l1->next;
        }
        //如果最后l1 l2均为NULL后仍进位1 仍需新建结点
        if(carray==1) {
            ListNode* temp=new ListNode(1);
            pre->next = temp;
            pre = pre->next;
        }
    }
    return pretmp->next;
}

//*****************************更加优雅的代码如下
ListNode *addTwoNumbers_elegant(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    //链表中值为非负数  所以val不存在时可设置为0
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;              //获取进位数值
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;      //为空则不改变
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}