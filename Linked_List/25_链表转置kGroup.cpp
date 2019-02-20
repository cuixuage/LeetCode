/*
间隔k个元素的转置
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
思路:
1.间隔k个元素找到节点end
2.转置[start,end)节点
3.拼接剩余的[end，...] 递归调用
*/
#include "func.h"

 ListNode* reverseKGroup(ListNode* head, int k) {
     if(head==NULL || k==0) return head;
     ListNode* end = head;
     for(int i=0;i<k;i++){
         if(end==NULL) return head; //1. 注意end位置
         end = end->next; 
     }
     ListNode* newHead = reverse(head,end); //2.
     head->next = reverseKGroup(end,k);      //3.
    return newHead;     //4. return节点
 }

// ->S...->E->...间隔链表的转置
 ListNode* reverse(ListNode* s, ListNode* e){
     ListNode* pre = NULL;
     while(s!=e){
         ListNode* tmp = s->next;
         s->next = pre;
         pre = s;
         s = tmp;
     }
     return pre;        //相当于return 初始的形参s节点,s->next=NULL而已
 }

/*
指针和引用的区别？
指针会新构建一个变量,而引用则不会
e.g.
int* p;
void func(int* p1){};
在指针传递中,实参是p,形参是p1这是两个不同的变量。
1.可以通过修改p1指向的变量,来改变p指向的变量
2.修改p1的值,不会改变p的值,即*p1不会改变

#include<iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode()    :val(0),next(NULL) {}
    ListNode(int x)    :val(x),next(NULL) {}
};

void func(ListNode* p){
    p = p->next;
    cout<<p->val<<endl;
}

void func2(ListNode*& p){       //指针变量的引用 可以成功修改
    p = p->next;
    cout<<p->val<<endl;
}

int main(){
    ListNode arr[3]={0};
    for(int i=0;i<2;i++){
        arr[i].val = i+1;
        arr[i].next = &arr[i+1];
    }
    arr[2].val = 3;
    arr[2].next = NULL;
    ListNode* p = &arr[0];
    cout<<p->val<<endl;
    func(p);
    cout<<p->val<<endl;
}
*/