/*  注意到以下情况
1.头结点指针为NULL
2.k==0
3.k值大于链表长度
*/
#include "func.h"
ListNode* findKthTail(ListNode* head,int k){
    if(head==NULL || k==0) return 0;
    ListNode* fast = head;
    for(int i=0;i<k;i++){
        if(fast==NULL) return NULL;     //k值大于链表长度
        fast = fast->next;
    }
    ListNode* slow = head;
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//推广2. 求链表中间节点
//fast slow指针


//推广3. 判断链表是否存在环路
//leetcode 141 一次AC 2017/12/25
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return false;   //1.
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next != NULL){             //2.尾节点
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }

//推广4. 如果链表存在环 返回cycle的起始结点
//leetcode142
ListNode *detectCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return NULL;
    ListNode* fast=head,*slow=head,*ans=head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) break;             //slow fast相遇后
    }
    if(fast==NULL || fast->next==NULL)
        return NULL;
    while(slow!=ans){                       //slow 与 此时出发的ans 必然相遇于cycle入口
        slow = slow->next;
        ans = ans->next;
    }
    return ans;
}


//leetcode142 方法2
//set 存储遍历过的结点  当出现第一个出现在set集合中结点即为cycle的入口