/* O(n)ʱ�����ж������Ƿ��������
    slow��fastѰ�ҵ������м�ֵ
    ����ת������ǰ��αȽ�
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
//**********************************************�ж��Ƿ�Ϊ��������
bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return true;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverseList(slow->next);   //���������ת��
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
head����ǵȴ�ת�õĽ�� pre������ת�õĽ�� next����head->next
��ʼ��pre��next
while(head!=NULL){
    ����next ����head->next
    ִ��ת�� head->next=pre
    ����preΪhead
    ����headΪnext
}
return pre;    //���һ�θ��� next=NULL  pre=head head=next;
}
��ͼ����
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
    arr1[0].val=1;   //�ǻ�������
    arr1[1].val=2;
    arr1[2].val=3;
    arr1[3].val=2;
    arr1[4].val=3;
    cout<<"bool is " <<isPalindrome(arr1)<<endl;
    return 0;
}
