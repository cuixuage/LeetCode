//������������ɾ���ظ����
//leetcode 83��
ListNode* deleteDuplicates(ListNode* head)
{
    if(head==NULL) return head;
    ListNode* pre = head;               //headָ�򲻱�
    ListNode* cur = head->next;         //�ؼ�
    while(cur!=NULL)
    {
        if(pre->val == cur->val)
            pre->next = cur->next;
        else
            pre = cur;
        cur = cur->next;
    }
    return head;
}

//�ƹ� ���ظ���Ԫ��ȫ��ɾ�� leetcode82  Given 1->1->1->2->3, return 2->3.
ListNode* deleteDuplicates(ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;

    ListNode *pre = new ListNode(0);
    pre->next = head;
    ListNode *temp=pre;
    while(head!=NULL)
    {
        //�ҵ��ظ�Ԫ�ص����һ��
        while(head->next!=NULL && head->val == head->next->val)
            head = head->next;

        //����preλ�á���ͣ�����ظ�Ԫ�ص�preλ��(û���ظ�Ԫ��)
        if(pre->next==head) pre = pre->next;
        //ָ���ظ�Ԫ�ص�nextλ��
        else pre->next=head->next;

        head = head->next;
    }
    return temp->next;

}
