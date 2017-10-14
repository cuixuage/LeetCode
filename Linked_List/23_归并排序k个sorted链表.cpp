/*
����1:��������������val���浽������,sort����,����val������µ�����
����2��k�������������Ƚ�
����3:ÿ��������ϲ�һ��
����4:���ȶ��� _���ȶ����Զ����� ��дcompare����
*/
#include<iostream>
#include<vector>
#include<limits>
using std::cout;
using std::endl;
using std::vector;

class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode():val(0),next(NULL) {}
    ListNode(int x)  :val(x),next(NULL) {}
};
//************************merge����sorted������
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* prev=new ListNode(INT_MIN);
    ListNode* temp=prev;
    while(l1&&l2){
        if(l1->val < l2->val){   //��������
            temp->next=l1;
            l1=l1->next;
        }
        else{
            temp->next=l2;
            l2=l2->next;
        }
        temp=temp->next;
    }
    temp->next=l1?l1:l2;  //���� l1����l2���ȳ�ʱ ��ʱ����һ��Ϊ��
    return prev->next;
}
//************************merge ����sorted������
ListNode* mergeKLists(vector<ListNode*> &lists){ //ʹ������ �ر��ǳ�������������ʱ��
    if(lists.empty()) return NULL;
    while(lists.size()>1){
        lists.push_back(mergeTwoLists(lists[0],lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    //return lists.front();
    return lists[0];
}

int main(int argc,char** argv){

}
