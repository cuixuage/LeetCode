/*�������    randomָ��null��������������һ���ڵ�
Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
�����Ҫע��:�������е�randomָ�벻����ָ��ԭ�������еĽڵ�
*/
#include<iostream>
#include<map>
#include<hash_map>
using std::cout;
using std::endl;
struct RandomListNode{
    int label;
    RandomListNode *next;
    RandomListNode *random;
    RandomListNode(int x)  //���ι��캯��
    :label(x)
    ,next(NULL)
    ,random(NULL){}
    RandomListNode()  //Ĭ�Ϲ��캯��
    :label(0)
    ,next(NULL)
    ,random(NULL){}
};

RandomListNode *copyRandomList(RandomListNode* head){
    if(head==NULL) return NULL;
    RandomListNode newList(0);
    RandomListNode *n = &newList; //������ͷ����preλ��
    RandomListNode *h = head;
    map<RandomListNode*,RandomListNode*> mapListNode;   //hashtableɢ�б����¾ɽ��֮��Ķ�Ӧ��ϵ
    while(h){
        RandomListNode* node = new RandomListNode(h->label);
        n->next = node;
        n = node;

        node->random = h->random; //�������randomָ��ָ����Ǿ�����ڵ�

        mapListNode[h] = node;  //�¾ɽ���ӳ���ϵ
        h = h->next;
    }
    h = newList.next;   // h = (&newList)->next;
    while(h!=NULL){     //�޸���������ÿһ��randomָ��ָ��������Ľ��
        if(h->random!=NULL)
            h->random = mapListNode[h->random];
        h = h->next;
    }
    return (&newList)->next;  //return newList.next �������ָ�� ȡ��Ա���÷�
}

int main(int argc,char** argv){

}
