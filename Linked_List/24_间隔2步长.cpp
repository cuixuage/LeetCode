/*
相邻两个步长 交换相邻元素
思路1:
参见25题 K个元素内部转置
*/
#include "func.h"

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