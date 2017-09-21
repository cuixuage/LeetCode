/*构建三个新节点
    一个保存所有奇数序号的链表
    一个保存所有偶数序号的链表
    一个保存偶数序号起始位置
https://leetcode.com/problems/odd-even-linked-list/solution/
*/
#include<iostream>
#include<algorithm>
#include<list>
using std::cout;
using std::endl;

struct ListNode{
    int data;
    ListNode *next;
}hashlistnode[100];

ListNode* oddEvenList(ListNode* head) {
    if(head==NULL) return head;
    ListNode* jishu=head, *oushu=head->next ,*store_first_oushu=head->next;
    while(oushu && oushu->next){
        jishu->next=oushu->next;   //所有奇数序号的结点
        jishu=jishu->next;

        oushu->next=jishu->next;
        oushu=oushu->next;
    }
    jishu->next=store_first_oushu;   //将偶数链表拼接到奇数链表的最后
    return head;
}
int main(){
    for(int i=0;i<100;i++){
        hashlistnode[i].data=i+1;
        if(i==99)   hashlistnode[i].next=NULL;
        else       hashlistnode[i].next=&hashlistnode[i+1];
    }
    ListNode *res=oddEvenList(hashlistnode);
    while(res!=NULL){
        cout<<res->data<<endl;
        res=res->next;
    }
    return 0;
}

