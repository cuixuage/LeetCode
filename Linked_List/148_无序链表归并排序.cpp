/*
�鲢���� �ݹ�ķ�ʽ O(nlogn) O(1)����鲢����Ҫ��������B ����ֻ��Ҫ����һ�����
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
ListNode * mergeList(ListNode *,ListNode* );

ListNode * sortList(ListNode * head){
    if(head==NULL || head->next==NULL) return head;
    //cut list to two halves
    ListNode *prev=NULL,*slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){   //ż����Ԫ��fast->next!=NULL
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;   //head��ǰ�벿��ͷ��� slow�Ǻ�벿��ͷ���
    //sort each half
    ListNode *L1=sortList(head);
    ListNode *L2=sortList(slow);
    //merge L1 and L2
    return mergeList(L1,L2);
}

//����������������ͷ���
ListNode * mergeList(ListNode *L1,ListNode* L2){
    ListNode *prev = new ListNode();
    ListNode *p=prev;
    while(L1!=NULL && L2!=NULL){
        if(L1->val < L2->val){
            p->next=L1;
            L1=L1->next;
        }
        else{
            p->next=L2;
            L2=L2->next;
        }
        p = p->next;
    }
    //����L1 L2���ȳ�
    if(L1!=NULL) p->next=L1;
    else if(L2!=NULL) p->next=L2;

    return prev->next;
}

//*************���� ������
void test1(){
    ListNode arrayList[7];
    for(int i=0;i<7;i++){
        arrayList[i].next = &arrayList[i+1];
    }
    arrayList[6]=NULL;
    arrayList[0].val=-1;
    arrayList[1].val=3;
    arrayList[2].val=3;
    arrayList[3].val=5;
    arrayList[4].val=7;
    arrayList[5].val=2;
    arrayList[6].val=0;
    ListNode * result = sortList(arrayList);
    while(result!=NULL){
        cout<< result->val << " ";
        result = result->next;
    }
}
int main(int argc,char** argv){
    //�ٲ�����������Ϊ��
    test1();
    return 0;
}



/*
//������ʽMergeSort�ؼ�����
void MergeSort(int* A,int left,int right,int* C)
{
	if(left < right)
	{
		int mid=(left+right)/2;
		MergeSort(A,left,mid,C);//�ź�һ������1
		MergeSort(A,mid+1,right,C);//�ź�һ������2
		Merge(A,left,mid,right,C); //�ϲ��������������
	}
}
*/
