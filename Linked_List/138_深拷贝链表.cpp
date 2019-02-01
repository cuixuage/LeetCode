/*
结构定义: ListNode含有next指针和random指针(随机指向一个节点或者为NULL)
深拷贝:
1.new ListNode开辟新空间
2.ListNode的next指针和random指针指向新的节点
注意:
random是不规律的,需要保存新旧节点地址的映射关系,再去替换random指向地址
*/

#include "func.h"
RandomListNode* copyRandomList(RandomListNode* head){
    if(head == NULL) return NULL;
    RandomListNode* pre = new RandomListNode(0);
    RandomListNode* pretmp = pre;
    RandomListNode* old = head;
    map<RandomListNode*,RandomListNode*> mapListNode;
    while(old != NULL){
        //1.
        RandomListNode* newNode = new RandomListNode(old->label);
        pre->next = newNode;
        pre = newNode;
        //2.
        newNode->random = old->random;  //新节点random指针指向的是旧节点地址
        mapListNode[old] = newNode;
        old = old->next;
    }
    //3. old指向新链表 开始遍历
    old = pretmp;
    while(old!=NULL){
        if(old->random != NULL)
            old->random = mapListNode[old->random];
        old = old->next;
    }
    RandomListNode* ans = pretmp->next;
    delete pretmp;
    return ans;
}