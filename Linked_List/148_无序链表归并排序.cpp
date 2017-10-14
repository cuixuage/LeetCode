/*
归并排序 递归的方式 O(nlogn) O(1)数组归并还需要辅助数组B 链表只需要额外一个结点
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
    ListNode(int x)   //有参构造函数
    :val(x),next(NULL) {}
};
ListNode * mergeList(ListNode *,ListNode* );

ListNode * sortList(ListNode * head){
    if(head==NULL || head->next==NULL) return head;
    //cut list to two halves
    ListNode *prev=NULL,*slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){   //偶数个元素fast->next!=NULL
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;   //head是前半部分头结点 slow是后半部分头结点
    //sort each half
    ListNode *L1=sortList(head);
    ListNode *L2=sortList(slow);
    //merge L1 and L2
    return mergeList(L1,L2);
}

//返回已排序好链表的头结点
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
    //链表L1 L2不等长
    if(L1!=NULL) p->next=L1;
    else if(L2!=NULL) p->next=L2;

    return prev->next;
}

//*************测试 排序结果
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
    //再测试输入链表为空
    test1();
    return 0;
}



/*
//数组形式MergeSort关键代码
void MergeSort(int* A,int left,int right,int* C)
{
	if(left < right)
	{
		int mid=(left+right)/2;
		MergeSort(A,left,mid,C);//排好一个数组1
		MergeSort(A,mid+1,right,C);//排好一个数组2
		Merge(A,left,mid,right,C); //合并两个有序的数组
	}
}
*/
