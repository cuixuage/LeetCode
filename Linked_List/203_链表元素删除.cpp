/*
方法1: 构建新节点,fakeNode->next=head, 循环判断fakeNode->next->val是否符合要求

方法2: 二重指针
*/
#include<stdio.h>
#include<iostream>
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

ListNode* removeElements_1(ListNode* head, int val) {
    ListNode *fakeNode=new ListNode(0);
    fakeNode->next=head;         //相当于head结点前加个空节点的新链表
    ListNode * res= fakeNode;
    while(fakeNode->next!=NULL){
        if(fakeNode->next->val==val)
            fakeNode->next=fakeNode->next->next;
        else fakeNode = fakeNode->next;
    }
    return res->next;
}

/*
错误:直接返回head   //思考 input:[1] output[1] Expected[]

我发现近几个题，只要是 返回的头指针在一开始不能确定，就可以用这个方法：
struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
dummy->next = head;
struct ListNode *p = dummy;
即建一个指向原head的指针dummy；循环时用p->next；最终返回是dummy->next。
*/

ListNode *removeElements_2(ListNode *head, int val)
{
    ListNode **list = &head;
    while (*list != nullptr){
        if ( (*list)->val == val )
            *list = (*list)->next;
        else
            list = &(*list)->next;
    }
    return head;
}
//看不懂的话看下面这个：（把head跟&head分开的写法，不易混）
//二级指针/双重指针的方法 跟 dummy 的思想是一样的。都是需要整一个能够指向head的东西~
ListNode* removeElements_3( ListNode* head, int val) {
    ListNode **prev, *curr;
    prev = &head;
    curr = head;
    while (curr) {
        if (curr->val == val)
            *prev = curr->next;
        else
            prev = &(curr->next);
        curr = curr->next;
    }
    return head;
}

int main(int argc,char** argv){
    ListNode arr1[5];
    for(int i=0;i<4;i++){
        arr1[i].next = &arr1[i+1];
    }
    arr1[4].next=NULL;
    arr1[0].val=1;   //非回文序列
    arr1[1].val=2;
    arr1[2].val=3;
    arr1[3].val=4;
    arr1[4].val=5;

    ListNode* res= removeElements_1(arr1,3);
    res= removeElements_2(res,4);
    res= removeElements_3(res,5);

    while(res!=NULL){
        cout<<" "<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
