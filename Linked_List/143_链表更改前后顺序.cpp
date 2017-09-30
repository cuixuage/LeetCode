/*
����������L��L 0��L 1������L n -1��L n��  ��������Ϊ��L 0��L n��L 1��L n -1��L 2��L n -2��
����{1,2,3,4}����������{1,4,2,3}��

����:��������ת��  ǰ�����������ٴν���ƴ��   �����������������ԱȻ�������234��Ŀ
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
    ListNode(int x)   //�вι��캯��
    :val(x),next(NULL) {}
};
ListNode* reverseList(ListNode* );
//*******************************************�����������������ԱȻ�������234��Ŀ
ListNode* reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next==NULL)
        return head;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
   // ListNode *preMiddle=slow;            //�м�ڵ�(����������ʼ���)��ǰһ���ڵ�
    slow->next=reverseList(slow->next);   //�õ�head������������ ���ν�����ת��
    ListNode *p1=head;
    ListNode *p2=slow->next;
    slow->next=NULL;               //�����и�Ϊ�������� p1Ϊԭ��ǰ�벿������
    ListNode *temp=NULL;
    while(p2!=nullptr){      //��Ԫ��Ϊ����ʱ��벿��������һ��Ԫ��
        temp=p2->next;
        p2->next=p1->next;  //p2���뵽 p1��p1->next֮��
        p1->next=p2;
        p1=p2->next;       //����p1,p2
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
