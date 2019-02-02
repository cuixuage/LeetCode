/*
将val小于x的节点放在链表前面,大于x的节点在链表后面
保持原有的相对顺序不改变
思路1:
list1，list2分别指向小于,大于的节点。最终将list1和list2拼接
思路2:
在原链表上操作相对复杂,两个指针交换节点(不使用？)
*/

#include "func.h"
ListNode* partition(ListNode* head,int x){
    ListNode* pre1 = new ListNode(0);
    ListNode* pre2 = new ListNode(0);
    ListNode* pre1tmp = pre1;
    ListNode* pre2tmp = pre2;
    while(head != NULL){
        if(head->val < x){
            pre1->next = head;
            pre1 = pre1->next;
        }else{
            pre2->next = head;
            pre2 =  pre2->next;
        }
        head = head->next;
    }
    //拼接list1 list2; 尾节点next指针置空
    pre1->next = pre2tmp->next;
    pre2->next = NULL;
    
    ListNode* ans = pre1tmp->next;
    delete pre1tmp;
    delete pre2tmp;
    return ans;
}