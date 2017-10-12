/* ������������ m n
�ӵ�m��Ԫ�ص���n��Ԫ�ؽ���ת��  �����ڵ�λ�ò���
��һ��ʹ�õ����ڱ����*/

#include <iostream>
using std::endl;
using std::cout;
class ListNode {
public:
    ListNode()
    :val(0),next(NULL) {}
    ListNode(int x)
    :val(x),next(NULL) {}
public:
    int val;
    ListNode* next;

};
//ListNode* reverseList(ListNode* head) {
//    ListNode* pre=NULL;
//    ListNode* next=NULL;
//    while(head!=NULL){
//        next=head->next;
//        head->next=pre;
//        pre=head;
//        head=next;
//    }
//    return pre;
//}
//ת��[m,n]����Ԫ��  ��һ��ʹ�õ����ڱ����
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL) return NULL;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    for(int i = 0; i<m-1; i++) pre = pre->next;

    ListNode* start = pre->next; // ��ת�õ��׽��
    ListNode* then = start->next; // ���m->next
//��ͼ��� ÿ�ΰѺ���һ��Ԫ�ز��뵽pre->next��
    for(int i=0; i<n-m; i++)
    {
        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next;  //����thenλ��
    }
    return dummy->next;
}
//*********************************����
int main(int argc,char** argv){
    ListNode arr1[6];
    for(int i=0;i<5;i++){
        arr1[i].val = i;
        arr1[i].next = &arr1[i+1];
    }
    arr1[5].val=6;
    arr1[5].next=NULL;

    ListNode * res=reverseBetween(arr1,2,5);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
