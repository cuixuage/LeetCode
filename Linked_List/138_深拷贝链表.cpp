/*深拷贝链表    random指向null或者链表中任意一个节点
Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
深拷贝需要注意:新链表中的random指针不能再指向原有链表中的节点
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
    RandomListNode(int x)  //含参构造函数
    :label(x)
    ,next(NULL)
    ,random(NULL){}
    RandomListNode()  //默认构造函数
    :label(0)
    ,next(NULL)
    ,random(NULL){}
};

RandomListNode *copyRandomList(RandomListNode* head){
    if(head==NULL) return NULL;
    RandomListNode newList(0);
    RandomListNode *n = &newList; //新链表头结点的pre位置
    RandomListNode *h = head;
    map<RandomListNode*,RandomListNode*> mapListNode;   //hashtable散列表保存新旧结点之间的对应关系
    while(h){
        RandomListNode* node = new RandomListNode(h->label);
        n->next = node;
        n = node;

        node->random = h->random; //新链表的random指针指向的是旧链表节点

        mapListNode[h] = node;  //新旧结点的映射关系
        h = h->next;
    }
    h = newList.next;   // h = (&newList)->next;
    while(h!=NULL){     //修改新链表中每一个random指针指向新链表的结点
        if(h->random!=NULL)
            h->random = mapListNode[h->random];
        h = h->next;
    }
    return (&newList)->next;  //return newList.next 区别对象、指针 取成员的用法
}

int main(int argc,char** argv){

}
