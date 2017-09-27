/*
寻找两条链表的交点(假设没有循环)
方法1: O(m*n) 对于A链表的每一个结点循环遍历链表B的所有节点 找到第一个交点位置
方法2: O(m+n) hash方法 hash表存储链表A每一个节点的地址 判断B的&是否存在散列集中
方法3：O(m+n) 空间O(1)
    只需要两次迭代。先到达尾节点的指针,下一次重定向到较长链表头部。
    如果pA再回到A的头部 虽然最后也能相遇 但是时间可能会很久 ; pA回到B的头部那么第二次pA,pB一定会相遇
*/

#include<stdio.h>
#include<iostream>
#include<list>
using std::cout;
using std::endl;

class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode()
    :val(0),next(NULL) {}
    ListNode(int x)   //有参构造函数
    :val(x),next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 =headA;
    ListNode *p2 =headB;
    if(p1==NULL || p2==NULL) return NULL;
    while(p1!=NULL && p2!=NULL &p1!=p2){
        p1=p1->next;
        p2=p2->next;
        if(p1==p2) return p1;        //如果没有交点返回NULL
        if(p1==NULL) p1=headA;
        if(p2==NULL) p2=headB;
    }
    return p2;
}
