/* 对比61题
删除倒数Nth位置的结点: fast指针比slow指针先出发 N
*/
#include<iostream>
using std::cout;
using std::endl;
class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode()    :val(0),next(NULL) {}
    ListNode(int x)    :val(x),next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n==0) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    // 写法2: for(int i=0;i <= n;i++)
    for (int i = 0; i < n ; i++) {
        first = first->next;
    }
    // 写法2: while (first!= NULL)
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
}

//*************测试
int main(int argc,char** argv){
    ListNode arr1[6];
    for(int i=0;i<5;i++){
        arr1[i].val = i;
        arr1[i].next = &arr1[i+1];
    }
    arr1[5].val=5;
    arr1[5].next=NULL;

    ListNode* res=removeNthFromEnd(&arr1[0],3);
    while(res!=NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
