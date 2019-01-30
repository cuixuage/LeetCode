#include "func.h"

ListNode* insertionSortList(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* cur = head;
    /*
    1.从哨兵节点dummy 寻找cur-next的合适位置
    2.pre->next指向cur->next; 链接原有的pre->next->next
    3.更新节点cur 和 pre
    */
    while(cur != NULL){
        //1.
        if(cur->next && cur->next->val < cur->val){
            while(pre->next && pre->next->val < cur->next->val)
                pre = pre->next;
            ListNode* tmp = pre->next;
            pre->next = cur->next; //2.
            cur->next = cur->next->next; //3. 移除cur->next节点
            pre->next->next = tmp;//2.
            pre = dummy;        //3.
        }
        else
            cur = cur->next;
    }
    //避免指针泄露
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}
/*
插入排序第一层循环
第二层循环 j<i && 将j放到前面已排序的合适位置
*/