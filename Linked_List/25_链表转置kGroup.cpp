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
class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode* end = head;
        //1.
        for(int i=0;i<k;i++){
            if(end==NULL) return head;
            end = end->next;
        }
        //2.
        ListNode* newHead = reverseList(head,end);
        //FIXME： 这里head并没有在reverseList中发生变化
        //指针和引用的区别
        head->next = reverseKGroup(end,k);
        return newHead;
    }
private:
    ListNode* reverseList(ListNode* head){
        //结束调用后 原head指针
        ListNode* pre = NULL;
        while(head!=NULL){
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* begin, ListNode* end){
        //结束调用后 原参数begin end的地址不会改变
        if(begin == end) return begin;
        ListNode* pre = NULL;
        ListNode* tmp = NULL;
        while(begin != end){
            tmp = begin->next;
            begin->next = pre;
            pre = begin;
            begin = tmp;
        }
        return pre;
    }
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