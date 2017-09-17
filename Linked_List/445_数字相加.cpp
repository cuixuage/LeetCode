/*
�����Ǹ��������
Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

����1�� ��ת������������
����2�� stack �洢��������������

����: c++ new����malloc����ָ�� java���Ƕ���
*/


#include<stdio.h>
#include<iostream>
#include<stack>
using std::cout;
using std::endl;
using std::stack;

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    stack<int> s1,s2;
    while(l1!=NULL){
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2!=NULL){
        s2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    ListNode *listFinal = new ListNode(0);
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()) { sum += s1.top(); s1.pop();}
        if(!s2.empty()) {sum += s2.top(); s2.pop();}
        listFinal->val = sum%10;                              //����ջ����Ԫ�����%10
        sum /= 10;
        ListNode * newNode = new ListNode(sum);               //�½ڵ�--��λֵ�ı���
        newNode->next = listFinal;
        listFinal = newNode;
    }
    return listFinal->val==0? listFinal->next:listFinal;
}

//����
int main(int argc ,char** argv){
    ListNode arr1[3],arr2[2];
    for(int i=0;i<2;i++){
        arr1[i].val = i+1;
        arr1[i].next = &arr1[i+1];
    }
    arr1[2].val=3;
    arr1[2].next=NULL;
    for(int i=0;i<1;i++){
        arr2[i].val = i+1;
        arr2[i].next = &arr2[i+1];
    }
    arr2[1].val=2;
    arr2[1].next=NULL;

    ListNode * result = addTwoNumbers(arr1,arr2);
    while(result!=NULL){
        cout<< result->val << " ";
        result = result->next;
    }
    return 0;
}
