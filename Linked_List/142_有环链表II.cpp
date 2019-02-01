/*
方法1:
fast slow指针相遇节点meet,和head节点同时同速度移动,再相遇节点即为entry节点
(有数学距离的推导)
方法2:
先得到环的节点数目n，使得meet节点先移动n步,head节点再同时同速度移动,这两个节点相遇点为entry节点
（更加直观？）
*/
#include "func.h"
class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* entry = head;
        ListNode* meet = meetingNode2(head);
        if(meet == NULL) return NULL;
        while(entry != meet){
            entry  = entry->next;
            meet = meet->next;
        }
        return entry;
    }
private:
    ListNode* meetingNode(ListNode* head){
        // fast多走了一步，使得最后meeting点的位置不满足推导公式
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next!=NULL && fast->next->next!=NULL){
            if(fast==slow) return fast;
            slow = slow->next;
            fast = fast->next->next;
        }
        return NULL;
    }
    ListNode* meetingNode2(ListNode* head){
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow) return fast;
        }
        return NULL;
    }
}
/*
证明:
核心idea:  fast的distance两倍于slow distance
L1： 起始点到环的入口点
L2： 环的入口点到slow.fast相遇点
C： 环的节点数目
N：fast指针绕环的次数
2(L1+L2) = L1+L2+N*C
即 L1 = C-L2 + (N-1)*C
即从head起始和meeting节点同时同速度,这两者相遇点即为入口点
*/