/*向右旋转k个位置 k是非负数
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
注意: k的大小可能大于链表长度

方法2: slow fast指针 其中fast比slow先运行k%length位置
最终slow->next指向切割点 fast->next指向头结点
*/
//终于一次性AC过了

#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){}
    ListNode(int x):val(x),next(NULL){}
};
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL ) return head;
    ListNode* pre = new ListNode(0);
    ListNode* cur = head;
    pre->next=head;
    int length=0;
    while(cur!=NULL){
        length++;
        cur = cur->next;
    }
    //注意当k%length时是不需要反转的
    k=length - k%length;
    if(k==length) return head;   //注意此时不需要反转的 否则会造成38行指针越界
    while(k--){
        pre=pre->next;
    }
    ListNode *temp=pre->next;
    pre->next=NULL;
    ListNode *fakenode=temp;
   while(temp->next!=NULL)
        temp=temp->next;
   temp->next = head;
   return fakenode;
}
int main(int argc,char** argv){
    ListNode arr[5];
    arr[0].val=1;
    arr[0].next=&arr[1];
    arr[1].val=2;
    arr[1].next=&arr[2];
    arr[2].val=3;
    arr[2].next=&arr[3];
    arr[3].val=4;
    arr[3].next=&arr[4];
    arr[4].val=5;
    arr[4].next=NULL;

    ListNode *result = rotateRight(arr,2);
    while(result!=NULL){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
