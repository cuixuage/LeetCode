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
    int La = getLength(headA);
    int Lb = getLength(headB);
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

//����2
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 =headA;
        ListNode *p2 =headB;

        if(p1==NULL || p2==NULL) return NULL;
        while(p1!=NULL && p2!=NULL &p1!=p2){
            p1=p1->next;
            p2=p2->next;
            if(p1==p2) return p1;
            if(p1==NULL) p1=headB;              //�ĳ�����һ�������ͷ��
            if(p2==NULL) p2=headA;
        }
        return p2;
    }
