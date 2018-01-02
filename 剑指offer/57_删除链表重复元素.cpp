//已排序链表中删除重复结点
//leetcode 83题
ListNode* deleteDuplicates(ListNode* head)
{
    if(head==NULL) return head;
    ListNode* pre = head;               //head指向不变
    ListNode* cur = head->next;         //关键
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

//推广 将重复的元素全部删除 leetcode82  Given 1->1->1->2->3, return 2->3.
ListNode* deleteDuplicates(ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;

    ListNode *pre = new ListNode(0);
    pre->next = head;
    ListNode *temp=pre;
    while(head!=NULL)
    {
        //找到重复元素的最后一个
        while(head->next!=NULL && head->val == head->next->val)
            head = head->next;

        //更新pre位置——停留在重复元素的pre位置(没有重复元素)
        if(pre->next==head) pre = pre->next;
        //指向重复元素的next位置
        else pre->next=head->next;

        head = head->next;
    }
    return temp->next;

}
