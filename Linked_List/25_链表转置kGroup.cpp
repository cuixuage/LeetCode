/* ����ת�� ÿK�����ת��һ��
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

#include<iostream>
using std::cout;
using std::endl;
class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode()    :val(0),next(NULL) {}
    ListNode(int x)    :val(x),next(NULL) {}
};
ListNode* reverseList(ListNode* first,ListNode* last) {
    ListNode* pre=last;   //�ص㡪��last�������Ҫת�õ�����Ԫ�ص�nextλ��
    ListNode* temp=new ListNode(0);
    while(first!=last){
        temp = first->next;
        first->next = pre;
        pre = first;
        first = temp;
    }
    return pre; //last��pre���
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
    return pre;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node=head;
    for (int i=0; i < k; ++i){
            if (node ==NULL) return head;  //�ݹ���ó���
            node = node->next;
    }
    ListNode* new_head = reverseList(head, node);
    head->next = reverseKGroup( node, k);   //ת�ú����һС������headΪβ�ڵ�
    return new_head;
}
int main(int argc,char** argv){
    ListNode arr1[6];
    for(int i=0;i<5;i++){
        arr1[i].val = i;
        arr1[i].next = &arr1[i+1];
    }
    arr1[5].val=5;
    arr1[5].next=NULL;
    cout<<"ok"<<endl;
    ListNode* res=reverseKGroup(&arr1[0],2);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}

/* ����:����ת�õĺ���
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
//********************************����: k=2ʱ ����24  ����2:
    ListNode* swapPairs(ListNode* head) {
            if(head==NULL || head->next==NULL) return head;
    ListNode* newHead = head->next, *a=head,*b=a->next,*pre = NULL;
    while(a!=NULL && b!=NULL){
      a->next = b->next;
      b->next = a;
      if(pre!=NULL) pre->next = b;
      if(a->next==NULL) break;
      b = a->next->next;
      pre = a;
      a = a->next;
    }
    return newHead;     //��ʼֵΪhead->next
    }
*/
