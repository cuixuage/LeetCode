//leetcode 206
ListNode* reverseList(ListNode* head){
    if(head == NULL) return NULL;
    ListNode* prev = NULL;            //指向上一个节点
    ListNode* next = NULL;            //指向下一个结点
    while(head!=NULL){                          //遍历所有节点
        next = head->next;
        head->next = prev;
        prev = head;                            //关键:两个更新步骤
        head = next;
    }
    return prev;
}

#include"func.h"
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}              //无参数的构造函数
    ListNode(int x) : val(x), next(NULL) {}
 };

/*
推广 leetcode92  转置序号[n,m]之间的链表
思路:  [m,n]之间链表转置
注意: 1.保存初始m 的prev结点
      2.保存m结点  (最后需要m结点指向原来n结点的next结点)
      3.最终 1步骤的结点的next指向 [m,n]转置链表的头结点
*/
ListNode* reverseBetween(ListNode* head, int m, int n) {
        //cout<<head->val;
        if(head == NULL ) return head;
        ListNode* ahead = new ListNode(0);
        ahead->next = head;
        ListNode* ahead2 = ahead;       //关键 哨兵结点的思想(保证next指向原有整个链表的所有元素)

        for(int i=0;i<m-1;i++)
            ahead = ahead->next;
        ListNode* mNode = ahead->next;
        ListNode* tail = ahead;         //初始m结点的prev结点

        ListNode* prev = NULL;
        ListNode* next = NULL;
        ahead = ahead->next;
        for(int i=m;i<=n;i++){
            next = ahead->next;
            ahead->next = prev;
            prev = ahead;
            ahead = next;
        }
        mNode->next = ahead;        //m结点
        tail->next = prev;
//        cout<<ahead2->next->val;
        return ahead2->next;
    }
/*
int  main(){
    ListNode mynode[5];         //注意: ListNode加上无参数的构造函数
    for(int i=0;i<4;i++){
        mynode[i].val = i+1;
        mynode[i].next = &mynode[i+1];
    }
    mynode[4].val = 5;
    mynode[4].next = NULL;

    ListNode* head = reverseBetween(mynode,1,2);
    while(head!=NULL){
        cout<<head->val<<" "<<endl;
        head = head->next;
    }
    return 0;
}
*/

//推广3. 每k个元素作为group反转一次

ListNode* reverseList(ListNode* first,ListNode* last) {
    ListNode* pre=last;   //重点——last结点是需要转置的链表元素的next位置
    ListNode* temp=new ListNode(0);
    while(first!=last){
        temp = first->next;
        first->next = pre;
        pre = first;
        first = temp;
    }
    return pre; //last的pre结点
}
ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node=head;
    for (int i=0; i < k; ++i){
            if (node ==NULL) return head;  //递归调用出口
            node = node->next;
    }
    //node 是第k+1个元素
    ListNode* new_head = reverseList(head, node);
    head->next = reverseKGroup( node, k);   //递归；；转置后的那一小段链表head为尾节点
    return new_head;
}
