/*ע��߽�����
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL && l2==NULL) return NULL;

    ListNode* tmp = new ListNode(0);    //���ڱ������ս��
    ListNode* head = tmp;
    while(l1!=NULL || l2!=NULL){             //�� l1==NULL&&l2==NULL ����ѭ��
        if(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;            //����
        }
        else{
            //l1==NULL?tmp->next=l2:tmp->next=l1;       //����д��
            tmp->next = l1==NULL?l2:l1;                 //l1&&l2��ΪNULL || ����һ��ΪNULL
            break;
        }
    }
    return head->next;
}

//�ƹ�2�� �ϲ�k�������������
