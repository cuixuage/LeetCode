/*
merge k sorted list
思路:  循环调用merge 2 list funtion

最优思路:  priority_queue
*/
#include "func.h"

ListNode* mergeKLists(vector<ListNode*>& lists){
    if(lists.size()==0) return NULL;
    // auto cmp = [](const ListNode* a, const ListNode* b)->bool{return a->val < b->val;};
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, compare> Q;

    ListNode* pre = new ListNode(0);
    ListNode* tmp = pre; 
    for(ListNode* node : lists)
        if(node!=NULL) Q.push(node);    //初始化

    while(!Q.empty()){
        tmp->next = Q.top();
        Q.pop();
        tmp = tmp->next;    //1.更新tmp位置
        if(tmp->next!=NULL)     //top节点所在的链表的下一个节点 
            Q.push(tmp->next);
    }
    //delete pre?
    return pre->next;
}




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