/*
��������������ɾ���ظ���Ԫ��
83��:
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
����:
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){}
    ListNode(int x):val(x),next(NULL){}
};

ListNode *deleteDuplicates(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode *pre = new ListNode(0);
    pre->next = head;
    ListNode *temp=pre;
    while(head!=NULL){
        //�ҵ��ظ�Ԫ�ص����һ��
        while(head->next!=NULL && head->val == head->next->val)  head = head->next;
        //����preλ�á���ͣ�����ظ�Ԫ�ص�preλ��
        if(pre->next==head) pre = pre->next;
        //ָ���ظ�Ԫ�ص�nextλ��
        else pre->next=head->next;
        head = head->next;
    }
    return temp->next;
}

int main(int argc,char** argv){
    ListNode arr[5];
    arr[0].val=1;
    arr[0].next=&arr[1];
    arr[1].val=1;
    arr[1].next=&arr[2];
    arr[2].val=1;
    arr[2].next=&arr[3];
    arr[3].val=2;
    arr[3].next=&arr[4];
    arr[4].val=3;
    arr[4].next=NULL;

    ListNode *result = deleteDuplicates(arr);
    while(result!=NULL){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
