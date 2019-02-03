/*
merge k sorted list
思路： 
循环调用merge 2 list funtion
*/
#include "func.h"

class solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0) return NULL;                //注意 此判断语句
        while(lists.size()>1){
            ListNode* l1 = lists[0];
            ListNode* l2 = lists[1];
            ListNode* merge = merge2List(l1,l2);
            lists.erase(lists.begin(),lists.begin()+2);  //删除[start,end)
            lists.push_back(merge);
        }
        return lists[0];
    }
private:
    ListNode* merge2List(ListNode* l1,ListNode* l2){
        ListNode* pre = new ListNode(0);
        ListNode* pretmp = pre;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                pre->next = l1;
                l1 = l1->next;
            }else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if(l1 == NULL) pre->next = l2;
        else pre->next = l1;
        ListNode* ans = pretmp->next;
        delete pretmp;
        return ans;
    }
}