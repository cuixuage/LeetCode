//leetcode 160 寻找链表的交集

//方法1: 链表长的先移动一定步数
int getLength(ListNode* head){
    int len = 0;
    ListNode* tmp = head;
    while(tmp!=NULL){
        len++;
        tmp = tmp->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    int La = getLength(ListNode* headA);
    int Lb = getLength(ListNode* headB);
    ListNode* longhead = headA;
    ListNode* shorthead = headB;
    int diff = std::abs(La - Lb);
    if(Lb > La){
        longhead = headB;
        shorthead = headA;
    }
    while(diff--){          //长链表先移动diff步
        longhead = longhead->next;
    }

    while(longhead!=NULL && shorthead!=NULL && longhead!=shorthead){
        longhead = longhead->next;
        shorthead = shorthead->next;
    }
    return longhead;
}
