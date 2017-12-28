/*  ע�⵽�������
1.ͷ���ָ��ΪNULL
2.k==0
3.kֵ����������
*/
ListNode* findKthTail(ListNode* head,int k){
    if(head==NULL || k==0)
        return NULL;
    ListNode* ahead = head;
    ListNode* slow = head;
    for(int i=0;i<k;i++){
        if(ahead->next!=NULL)               //�ؼ�3.��ֹk��ֵ���������ȵ����
            ahead = ahead->next;
        else
            return NULL;
    while(ahead->next!=NULL){
        slow = slow->next;
        ahead = ahead->next;
    }
    return slow;
}

//�ƹ�2. �������м�ڵ�
//fast slowָ��


//�ƹ�3. �ж������Ƿ���ڻ�·
//leetcode 141 һ��AC 2017/12/25
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return false;   //1.
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next != NULL){             //2.β�ڵ�
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }

//�ƹ�4. ���������ڻ� ����cycle����ʼ���
//leetcode142
ListNode *detectCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return NULL;
    ListNode* fast=head,*slow=head,*ans=head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) break;             //slow fast������
    }
    if(fast==NULL || fast->next==NULL)
        return NULL;
    while(slow!=ans){                       //slow �� ��ʱ������ans ��Ȼ������cycle���
        slow = slow->next;
        ans = ans->next;
    }
    return ans;
}


//leetcode142 ����2
//set �洢�������Ľ��  �����ֵ�һ��������set�����н�㼴Ϊcycle�����
