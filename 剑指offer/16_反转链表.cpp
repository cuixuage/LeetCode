#include "func.h"
//一次AC
ListNode* reverse(ListNode* head){
    if(head==NULL) return NULL;
    ListNode* pre = NULL;
    while(head){
        ListNode* tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}

/*
转置[m,n]之间的链表,首节点的序号是1
思路1:
单独取出[m,n]之间链表,对其转置,再加入原链表
思路2:
1.one-pass 哨兵节点为m-1点
2.将m,n的节点按顺序加入哨兵节点后侧即为转置
*/
ListNode* reverseBetween(ListNode* head,int m,int n){
    if(head==NULL) return NULL;
    //1. 哨兵节点
    ListNode* pre = new ListNode(0);       
    ListNode* pre_2 = pre;
    pre->next = head;
    for(int i=0;i<m-1;i++) pre = pre->next;
    /*
    2. start是序号m的节点 不断将then加入pre后侧
    对于每一轮来说,then插入pre，pre->next之间
    then的前置节点是哨兵节点, then->next指向节点是pre->next节点
    */
    ListNode* start = pre->next;
    ListNode* then = start->next;  
    for(int i=m;i<n;i++){
        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next; 
    }
    ListNode* ans = pre_2->next;
    delete pre_2;
    return ans;
}

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
        //1.note: end节点位置
        for(int i=0;i<k;i++){
            if(end==NULL) return head;
            end = end->next;
        }
        //2.
        ListNode* newHead = reverseList(head,end);
        //head被移动到末尾 + 递归
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
        //结束调用后 形参begin end的地址不会改变
        //但是其内部属性 ->next指向发生了改变,begin相当于位于链表的结尾处 
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

//*************************2刷 AC

/*
1. 间隔K翻转 
2.翻转 [head,end)间隔;   转置后head处于本间隔的尾节点
3.递归 end,k.  end时后半部分链表的头结点
*/
 ListNode* reverseKGroup(ListNode* head, int k) {
     if(head==NULL || k==0) return head;
     ListNode* end = head;
     for(int i=0;i<k;i++){
         if(end==NULL) return head; //1.
         end = end->next; 
     }
     ListNode* newHead = reverse(head,end); //2.
     head->next = reverseKGroup(end,k);      //3.
    return newHead;     //4. return节点
 }

// ->S...->E->...间隔链表的转置
 ListNode* reverse(ListNode* s, ListNode* e){
     ListNode* pre = NULL;
     while(s!=e){
         ListNode* tmp = s->next;
         s->next = pre;
         pre = s;
         s = tmp;
     }
     return pre;        //相当于return 初始的形参s节点,s->next=NULL而已
 }