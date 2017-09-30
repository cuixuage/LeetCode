/*
给出单链表L：L 0？L 1？？？L n -1？L n，  重新排序为：L 0？L n？L 1？L n -1？L 2？L n -2？
给定{1,2,3,4}，重新排序{1,4,2,3}。

方法:后半段链表转置  前后两段链表再次交叉拼接   ————————对比回文链表234题目
*/

#include<stdio.h>
#include<iostream>
#include<list>
using std::cout;
using std::endl;

class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode()
    :val(0),next(NULL) {}
    ListNode(int x)   //有参构造函数
    :val(x),next(NULL) {}
};
ListNode* reverseList(ListNode* );
//*******************************************————————对比回文链表234题目
ListNode* reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next==NULL)
        return head;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
   // ListNode *preMiddle=slow;            //中间节点(后半段链表起始结点)的前一个节点
    slow->next=reverseList(slow->next);   //得到head起点的完整链表 后半段进行了转置
    ListNode *p1=head;
    ListNode *p2=slow->next;
    slow->next=NULL;               //彻底切割为两个链表 p1为原来前半部分链表
    ListNode *temp=NULL;
    while(p2!=nullptr){      //总元素为奇数时后半部分链表少一个元素
        temp=p2->next;
        p2->next=p1->next;  //p2插入到 p1和p1->next之间
        p1->next=p2;
        p1=p2->next;       //更新p1,p2
        p2=temp;
    }
    return head;
}
ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    //cout<<"reverse ok"<<endl;
    return pre;
}

int main(int argc,char** argv){
    ListNode arr1[5];
    for(int i=0;i<4;i++){
        arr1[i].next = &arr1[i+1];
    }
    arr1[4].next=NULL;
    arr1[0].val=1;
    arr1[1].val=2;
    arr1[2].val=3;
    arr1[3].val=4;
    arr1[4].val=5;
    ListNode * res=reorderList(arr1);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
