/*注意边界问题
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL && l2==NULL) return NULL;

    ListNode* tmp = new ListNode(0);    //用于保存最终结果
    ListNode* head = tmp;
    while(l1!=NULL || l2!=NULL){             //当 l1==NULL&&l2==NULL 跳出循环
        if(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;            //更新
        }
        else{
            //l1==NULL?tmp->next=l2:tmp->next=l1;       //错误写法
            tmp->next = l1==NULL?l2:l1;                 //l1&&l2均为NULL || 其中一个为NULL
            break;
        }
    }
    return head->next;
}

//推广2： 合并k个已排序的链表
