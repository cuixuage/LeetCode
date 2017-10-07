/*�����������л��Ľ������� �޻�����NULL
    //�ж��Ƿ������л�
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
//�ж��Ƿ��л�  �����ؽ�����
ListNode *detectCycle(ListNode *head){
    if(head==NULL || head->next==NULL) return NULL;
    ListNode *slow=head;
    ListNode *fast=head;
    ListNode *entry=head;  //�������
    while(fast!=NULL &&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    if(fast==NULL || fast->next==NULL)  //Ԫ�ظ���Ϊ����ʱͨ��fast->next�ж�
        return NULL;

    //��head������entry ��Ȼ�� �ƻ�����slow��������ڻ������
    if(slow==fast){
        //entry=head;
        while(entry!=slow){
            slow = slow->next;
            entry = entry->next;
        }
    }
    return entry;
}

//************************����
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

����: ��head��㵽�����ĳ��� == slow��fast�����������ƻ�ֱ�������ľ���+(n-1)*������

����: fast������ߵľ�����slow������߳��ȵ�����
��slow���������ƻ�һ��  fast��slow���뻷ǰ�����Ѿ��ƻ���Σ�
2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)*
*/
