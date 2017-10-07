/*返回链表中有环的交叉点起点 无环返回NULL
    //判断是否链表有环
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) return true;
    }
*/
#include<stdio.h>
#include<iostream>
using std::cout;
using std::endl;
class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode()
    :val(0),next(NULL) {}
    ListNode(int x)
    :val(x),next(NULL) {}
};
//判断是否有环  并返回交叉结点
ListNode *detectCycle(ListNode *head){
    if(head==NULL || head->next==NULL) return NULL;
    ListNode *slow=head;
    ListNode *fast=head;
    ListNode *entry=head;  //环交叉点
    while(fast!=NULL &&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    if(fast==NULL || fast->next==NULL)  //元素个数为奇数时通过fast->next判断
        return NULL;

    //由head出发的entry 必然与 绕环行走slow结点相遇于环交叉点
    if(slow==fast){
        //entry=head;
        while(entry!=slow){
            slow = slow->next;
            entry = entry->next;
        }
    }
    return entry;
}

//************************测试
int main(int argc,char** argv){
    ListNode arr1[10];
    for(int i=0;i<9;i++){
        arr1[i].val=i;
        arr1[i].next = &arr1[i+1];
    }
    arr1[9].val=9;
    arr1[9].next=&arr1[5];
    ListNode * res=detectCycle(arr1);
    if(res==NULL) cout<<"no cycle"<<endl;
    else cout<<"cycle entry is "<<res->val<<endl;

    return 0;
}
/*
https://leetcode.com/problems/linked-list-cycle-ii/discuss/

含义: 从head结点到交叉点的长度 == slow与fast相遇结点继续绕环直到交叉点的距离+(n-1)*环长度

依据: fast结点行走的距离是slow结点行走长度的两倍
故slow不会完整绕环一次  fast在slow进入环前可能已经绕环多次！
2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)*
*/
