/*
反向打印链表
思路1:
转置链表后返回  
由于转置函数内部不是简单的地址移动 还有改变head->next指向导致改变原有的链表结构
思路2:
stack保存val
*/
#include "func.h"
vector<int> printListFromTailToHead(ListNode* head){
    stack<int> vals;
    while(head){
        vals.push(head->val);
        head = head->next;
    }
    vector<int> ans;
    while(!vals.empty()){
        ans.push_back(vals.top());
        vals.pop();
    }
    return ans;
}