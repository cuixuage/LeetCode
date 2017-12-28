//leetcode 206
ListNode* reverseList(ListNode* head){
    if(head == NULL) return NULL;
    ListNode* prev = NULL;            //ָ����һ���ڵ�
    ListNode* next = NULL;            //ָ����һ�����
    while(head!=NULL){                          //�������нڵ�
        next = head->next;
        head->next = prev;
        prev = head;                            //�ؼ�:�������²���
        head = next;
    }
    return prev;
}

#include"func.h"
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}              //�޲����Ĺ��캯��
    ListNode(int x) : val(x), next(NULL) {}
 };

/*
�ƹ� leetcode92  ת�����[n,m]֮�������
˼·:  [m,n]֮������ת��
ע��: 1.�����ʼm ��prev���
      2.����m���  (�����Ҫm���ָ��ԭ��n����next���)
      3.���� 1����Ľ���nextָ�� [m,n]ת�������ͷ���
*/
ListNode* reverseBetween(ListNode* head, int m, int n) {
        //cout<<head->val;
        if(head == NULL ) return head;
        ListNode* ahead = new ListNode(0);
        ahead->next = head;
        ListNode* ahead2 = ahead;       //�ؼ� �ڱ�����˼��(��֤nextָ��ԭ���������������Ԫ��)

        for(int i=0;i<m-1;i++)
            ahead = ahead->next;
        ListNode* mNode = ahead->next;
        ListNode* tail = ahead;         //��ʼm����prev���

        ListNode* prev = NULL;
        ListNode* next = NULL;
        ahead = ahead->next;
        for(int i=m;i<=n;i++){
            next = ahead->next;
            ahead->next = prev;
            prev = ahead;
            ahead = next;
        }
        mNode->next = ahead;        //m���
        tail->next = prev;
//        cout<<ahead2->next->val;
        return ahead2->next;
    }
/*
int  main(){
    ListNode mynode[5];         //ע��: ListNode�����޲����Ĺ��캯��
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

//�ƹ�3. ÿk��Ԫ����Ϊgroup��תһ��

ListNode* reverseList(ListNode* first,ListNode* last) {
    ListNode* pre=last;   //�ص㡪��last�������Ҫת�õ�����Ԫ�ص�nextλ��
    ListNode* temp=new ListNode(0);
    while(first!=last){
        temp = first->next;
        first->next = pre;
        pre = first;
        first = temp;
    }
    return pre; //last��pre���
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
            if (node ==NULL) return head;  //�ݹ���ó���
            node = node->next;
    }
    //node �ǵ�k+1��Ԫ��
    ListNode* new_head = reverseList(head, node);
    head->next = reverseKGroup( node, k);   //�ݹ飻��ת�ú����һС������headΪβ�ڵ�
    return new_head;
}
