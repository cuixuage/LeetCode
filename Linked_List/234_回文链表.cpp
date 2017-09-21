/* O(n)时间内判断链表是否回文序列
    slow、fast寻找到链表中间值
    后半段转置再与前半段比较
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
//**********************************************判断是否为回文链表
bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return true;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverseList(slow->next);   //后半段链表的转置
    slow=slow->next;
    while(slow!=NULL){
        if(head->val!=slow->val)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;
}
/*
head结点是等待转置的结点 pre保存已转置的结点 next保存head->next
初始化pre、next
while(head!=NULL){
    更新next 保存head->next
    执行转置 head->next=pre
    更新pre为head
    更行head为next
}
return pre;    //最后一次更新 next=NULL  pre=head head=next;
}
画图记忆
*/
ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}

int main(int argc,char** argv){
    ListNode arr1[5];
    for(int i=0;i<4;i++){
        arr1[i].next = &arr1[i+1];
    }
    arr1[4].next=NULL;
    arr1[0].val=1;   //非回文序列
    arr1[1].val=2;
    arr1[2].val=3;
    arr1[3].val=2;
    arr1[4].val=3;
    cout<<"bool is " <<isPalindrome(arr1)<<endl;
    return 0;
}
