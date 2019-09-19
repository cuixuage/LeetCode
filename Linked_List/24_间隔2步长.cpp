/*
相邻两个步长 交换相邻元素
思路1:
参见25题 K个元素内部转置
*/
#include "func.h"

// 间隔K个步长转置   递归实现
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        ListNode* end = head;
        int K = 2;
        for(int i=0;i<K;i++){
            if(end==NULL) return head;
            end = end->next;
        }
        ListNode* newHead = reverseList(head,end);
        head->next = swapPairs(end);
        return newHead;
    }
private:
    ListNode* reverseList(ListNode* begin, ListNode* end){
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

//间隔2个步长的递归实现
ListNode* swapPairs(ListNode* head){
    //0.
    if(head==NULL || head->next==NULL) return head;
    //1. 画图理解诶
    ListNode* tmp = head->next;
    //2.递归
    head->next = swapPairs(head->next->next);
    //3.重新拼接
    tmp->next = head;

    return tmp;
}

//////间隔两个步长的非递归实现
ListNode* swapPairs(ListNode* head){
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* tmp = pre;
    while(head!=NULL && head->next!=NULL){
        ListNode* tmp = head->next;     //保存head->next
        head->next = tmp->next;         //head->next指向第三个节点
        tmp->next = head;               //tmp指向head 
        pre->next = tmp;                //pre节点和转置pair后的做拼接

        pre = head;             //更新
        head = pre->next;
    }
    return tmp->next;
}
