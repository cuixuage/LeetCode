/*
����1: �����½ڵ�,fakeNode->next=head, ѭ���ж�fakeNode->next->val�Ƿ����Ҫ��

����2: ����ָ��
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
    ListNode(int x)   //�вι��캯��
    :val(x),next(NULL) {}
};

ListNode* removeElements_1(ListNode* head, int val) {
    ListNode *fakeNode=new ListNode(0);
    fakeNode->next=head;         //�൱��head���ǰ�Ӹ��սڵ��������
    ListNode * res= fakeNode;
    while(fakeNode->next!=NULL){
        if(fakeNode->next->val==val)
            fakeNode->next=fakeNode->next->next;
        else fakeNode = fakeNode->next;
    }
    return res->next;
}

/*
����:ֱ�ӷ���head   //˼�� input:[1] output[1] Expected[]

�ҷ��ֽ������⣬ֻҪ�� ���ص�ͷָ����һ��ʼ����ȷ�����Ϳ��������������
struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
dummy->next = head;
struct ListNode *p = dummy;
����һ��ָ��ԭhead��ָ��dummy��ѭ��ʱ��p->next�����շ�����dummy->next��
*/

ListNode *removeElements_2(ListNode *head, int val)
{
    ListNode **list = &head;
    while (*list != nullptr){
        if ( (*list)->val == val )
            *list = (*list)->next;
        else
            list = &(*list)->next;
    }
    return head;
}
//�������Ļ����������������head��&head�ֿ���д�������׻죩
//����ָ��/˫��ָ��ķ��� �� dummy ��˼����һ���ġ�������Ҫ��һ���ܹ�ָ��head�Ķ���~
ListNode* removeElements_3( ListNode* head, int val) {
    ListNode **prev, *curr;
    prev = &head;
    curr = head;
    while (curr) {
        if (curr->val == val)
            *prev = curr->next;
        else
            prev = &(curr->next);
        curr = curr->next;
    }
    return head;
}

int main(int argc,char** argv){
    ListNode arr1[5];
    for(int i=0;i<4;i++){
        arr1[i].next = &arr1[i+1];
    }
    arr1[4].next=NULL;
    arr1[0].val=1;   //�ǻ�������
    arr1[1].val=2;
    arr1[2].val=3;
    arr1[3].val=4;
    arr1[4].val=5;

    ListNode* res= removeElements_1(arr1,3);
    res= removeElements_2(res,4);
    res= removeElements_3(res,5);

    while(res!=NULL){
        cout<<" "<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
