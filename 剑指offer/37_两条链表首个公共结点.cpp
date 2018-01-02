//leetcode 160 Ѱ������Ľ���

//����1: ���������ƶ�һ������
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
    while(diff--){          //���������ƶ�diff��
        longhead = longhead->next;
    }

    while(longhead!=NULL && shorthead!=NULL && longhead!=shorthead){
        longhead = longhead->next;
        shorthead = shorthead->next;
    }
    return longhead;
}
