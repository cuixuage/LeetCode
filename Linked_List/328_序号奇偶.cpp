/*���������½ڵ�
    һ����������������ŵ�����
    һ����������ż����ŵ�����
    һ������ż�������ʼλ��
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
        jishu->next=oushu->next;   //����������ŵĽ��
        jishu=jishu->next;

        oushu->next=jishu->next;
        oushu=oushu->next;
    }
    jishu->next=store_first_oushu;   //��ż������ƴ�ӵ�������������
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

