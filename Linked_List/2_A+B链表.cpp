/* ���ַ���洢 ע���λ����
��������ǰ����
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
�о���21�� 23�� merge sorted������Щ����
*/

//һ��ͨ��  accepted
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
//*****************************�������ŵĴ�������
ListNode *addTwoNumbers_elegant(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    //������ֵΪ�Ǹ���  ����val������ʱ������Ϊ0
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;              //��ȡ��λ��ֵ
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;      //Ϊ���򲻸ı�
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
//************************************************************
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode* prev = new ListNode(0);
    ListNode* dummy = prev;
    while(l1&&l2){
        int sum=l1->val+l2->val+carry;
        if(sum>=10) carry=1;
        else carry=0;
        ListNode* temp=new ListNode(sum%10);
        prev->next = temp;
        prev = prev->next;
        l1=l1->next;
        l2=l2->next;
    }

    if(l1==NULL){
        while(l2!=NULL){
            int sum=l2->val + carry;
            if(sum>=10) carry=1;
            else carry=0;
            ListNode* temp=new ListNode(sum%10);
            prev->next = temp;
            prev = prev->next;
            l2=l2->next;
        }
        //������l1 l2��ΪNULL���Խ�λ1 �����½����
        if(carry==1) {
            ListNode* temp=new ListNode(1);
            prev->next = temp;
            prev = prev->next;
        }
    }
    else if(l2==NULL){
        while(l1!=NULL){
            int sum=l1->val + carry;
            if(sum>=10) carry=1;
            else carry=0;
            ListNode* temp=new ListNode(sum%10);
            prev->next = temp;
            prev = prev->next;
            l1=l1->next;
        }
        if(carry==1) {
            ListNode* temp=new ListNode(1);
            prev->next = temp;
            prev = prev->next;
        }
    }
    return dummy->next;
}
//***********************************����11118+222229  ��λ
int main(int argc,char** argv){
    ListNode arr1[5];
    for(int i=0;i<4;i++){
        arr1[i].val = 1;
        arr1[i].next = &arr1[i+1];
    }
    arr1[4].val=8;
    arr1[4].next=NULL;
    ListNode arr2[6];
    for(int i=0;i<5;i++){
        arr2[i].val = 2;
        arr2[i].next = &arr2[i+1];
    }
    arr2[5].val=9;
    arr2[5].next=NULL;

    //ListNode* res=addTwoNumbers(&arr1[0],&arr2[0]);
    ListNode* res=addTwoNumbers_elegant(&arr1[0],&arr2[0]);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
