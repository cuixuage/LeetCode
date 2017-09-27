/*
Ѱ����������Ľ���(����û��ѭ��)
����1: O(m*n) ����A�����ÿһ�����ѭ����������B�����нڵ� �ҵ���һ������λ��
����2: O(m+n) hash���� hash��洢����Aÿһ���ڵ�ĵ�ַ �ж�B��&�Ƿ����ɢ�м���
����3��O(m+n) �ռ�O(1)
    ֻ��Ҫ���ε������ȵ���β�ڵ��ָ��,��һ���ض��򵽽ϳ�����ͷ����
    ���pA�ٻص�A��ͷ�� ��Ȼ���Ҳ������ ����ʱ����ܻ�ܾ� ; pA�ص�B��ͷ����ô�ڶ���pA,pBһ��������
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 =headA;
    ListNode *p2 =headB;
    if(p1==NULL || p2==NULL) return NULL;
    while(p1!=NULL && p2!=NULL &p1!=p2){
        p1=p1->next;
        p2=p2->next;
        if(p1==p2) return p1;        //���û�н��㷵��NULL
        if(p1==NULL) p1=headA;
        if(p2==NULL) p2=headB;
    }
    return p2;
}
