/* ����С��ĳ��valֵ���ڴ��ڵ���valֵ��ǰ�� */
#include<iostream>
using std::cout;
using std::endl;

struct ListNode{
    int val;
    ListNode* next;
    ListNode()
    :val(0)
    ,next(NULL){}
    ListNode(int x)
    :val(x)
    ,next(NULL){}
};

ListNode *partition_test(ListNode*head ,int x){
    ListNode node1(0),node2(0);
    ListNode *p1=&node1,*p2=&node2;
    while(head!=NULL){                //С��x�Ľ�����ӵ�node1
        if(head->val < x){
            p1->next = head;
            p1 = p1->next;
        }
        else{                          //���ڵ���x�Ľ�����ӵ�node2
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;             //�˲�������
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}

//*****************************����
int main(int argc,char** argv){
    ListNode arr1[6];
    arr1[0].val=6;
    arr1[0].next=&arr1[1];

    arr1[1].val=5;
    arr1[1].next=&arr1[2];

    arr1[2].val=4;
    arr1[2].next=&arr1[3];

    arr1[3].val=3;
    arr1[3].next=&arr1[4];

    arr1[4].val=2;
    arr1[4].next=&arr1[5];

    arr1[5].val=1;
    arr1[5].next=NULL;
    cout<<"ok1"<<endl;
    ListNode * res=partition_test(arr1,3);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
