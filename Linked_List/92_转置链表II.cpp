/* 给定两个参数 m n
从第m个元素到第n个元素进行转置  其它节点位置不变
再一次使用到了哨兵结点*/

#include <iostream>
using std::endl;
using std::cout;
class ListNode {
public:
    ListNode()
    :val(0),next(NULL) {}
    ListNode(int x)
    :val(x),next(NULL) {}
public:
    int val;
    ListNode* next;

};
//ListNode* reverseList(ListNode* head) {
//    ListNode* pre=NULL;
//    ListNode* next=NULL;
//    while(head!=NULL){
//        next=head->next;
//        head->next=pre;
//        pre=head;
//        head=next;
//    }
//    return pre;
//}
//转置[m,n]区间元素  再一次使用到了哨兵结点
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL) return NULL;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    for(int i = 0; i<m-1; i++) pre = pre->next;

    ListNode* start = pre->next; // 待转置的首结点
    ListNode* then = start->next; // 结点m->next
//画图理解 每次把后面一个元素插入到pre->next后
    for(int i=0; i<n-m; i++)
    {
        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next;  //更新then位置
    }
    return dummy->next;
}
//*********************************测试
int main(int argc,char** argv){
    ListNode arr1[6];
    for(int i=0;i<5;i++){
        arr1[i].val = i;
        arr1[i].next = &arr1[i+1];
    }
    arr1[5].val=6;
    arr1[5].next=NULL;

    ListNode * res=reverseBetween(arr1,2,5);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
