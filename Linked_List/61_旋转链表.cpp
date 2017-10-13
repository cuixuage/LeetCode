/*������תk��λ�� k�ǷǸ���
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
ע��: k�Ĵ�С���ܴ���������

����2: slow fastָ�� ����fast��slow������k%lengthλ��
����slow->nextָ���и�� fast->nextָ��ͷ���
*/
//����һ����AC����

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
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL ) return head;
    ListNode* pre = new ListNode(0);
    ListNode* cur = head;
    pre->next=head;
    int length=0;
    while(cur!=NULL){
        length++;
        cur = cur->next;
    }
    //ע�⵱k%lengthʱ�ǲ���Ҫ��ת��
    k=length - k%length;
    if(k==length) return head;   //ע���ʱ����Ҫ��ת�� ��������38��ָ��Խ��
    while(k--){
        pre=pre->next;
    }
    ListNode *temp=pre->next;
    pre->next=NULL;
    ListNode *fakenode=temp;
   while(temp->next!=NULL)
        temp=temp->next;
   temp->next = head;
   return fakenode;
}
int main(int argc,char** argv){
    ListNode arr[5];
    arr[0].val=1;
    arr[0].next=&arr[1];
    arr[1].val=2;
    arr[1].next=&arr[2];
    arr[2].val=3;
    arr[2].next=&arr[3];
    arr[3].val=4;
    arr[3].next=&arr[4];
    arr[4].val=5;
    arr[4].next=NULL;

    ListNode *result = rotateRight(arr,2);
    while(result!=NULL){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
