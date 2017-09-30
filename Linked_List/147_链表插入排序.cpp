//��������ʱ����O(n*n)
//ÿ�ε����ǿ���һ��valС������ǰ�ڵ�Ľڵ�ʱ�����Ǵ���head�ҳ���ǰ�ڵ�Ӧ�ñ������λ�á�
//���ڿ��Բ���ڵ�head���������Ǵ���һ��new_headָ��Ľڵ�head
#include<stdio.h>
#include<iostream>
#include<list>
using std::cout;
using std::endl;

class ListNode
{
public:
    int val;
    ListNode *next;
public:
    ListNode()
        :val(0),next(NULL) {}
    ListNode(int x)   //�вι��캯��
        :val(x),next(NULL) {}
};
//��ͼ���
//�����ⶼ��Ҫһ��pre���ָ��ͷ���
ListNode * insertSortList(ListNode* head)
{
    ListNode* new_head = new ListNode(0);
    new_head -> next = head;
    ListNode* pre = new_head;
    ListNode* cur = head;
    //curǰ���Լ�cur�������������
    while (cur)
    {
        if (cur -> next && cur -> next -> val < cur -> val)     //cur->next�ǽ�С����ֵ ��ǰ���ҵ�ǡ����λ��
        {
            while (pre -> next && pre -> next -> val < cur -> next -> val)  //pre��ͷ��ʼѰ��
                pre = pre -> next;
            /* Insert cur -> next after pre.*/    //pre->next���ڵ���cur->next
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;           //����cur->next
            cur -> next = cur -> next -> next;   //ԭ�����cur->next�Ƴ���λ�õ�����
            pre -> next -> next = temp;          //�����λ�õ�����
            /* Move pre back to new_head. */
            pre = new_head;
        }
        else cur = cur -> next;  //cur->nextֵ����curʱ
    }
    ListNode* res = new_head -> next;
    delete new_head;
    return res;
}


//*************���� ������
void test1()
{
    ListNode arrayList[7];
    for(int i=0; i<7; i++)
    {
        arrayList[i].next = &arrayList[i+1];
    }
    arrayList[6]=NULL;
    arrayList[0].val=-1;
    arrayList[1].val=3;
    arrayList[2].val=3;
    arrayList[3].val=5;
    arrayList[4].val=7;
    arrayList[5].val=2;
    arrayList[6].val=0;
    ListNode * result = insertSortList(arrayList);
    while(result!=NULL)
    {
        cout<< result->val << " ";
        result = result->next;
    }
}
int main(int argc,char** argv)
{
    //�ٲ�����������Ϊ��
    test1();
    return 0;
}


/*
//����Ԫ��ȡ�����������������������Ԫ�رȽϣ�����������Ԫ�ش�����Ԫ�أ���ô����Ԫ���ƶ�����һ��λ�ã���������ǰ����������Ԫ�رȽϣ�ֱ���ҵ��������Ԫ��С�ڵ�����Ԫ�ص�λ�ã���ʱ�ٽ���Ԫ�ز����ȥ
void insertion_sort(int arr[], int len)
 2 {
 3     for (int i = 1, j = 0 ; i < len; ++i)    //�Ա�len - 1�Σ�ֱ�����ֻʣһ����
 4     {
 5         int temp = arr[i];  //tempΪ�ؼ���
 6         for (j = i - 1; j >= 0 && arr[j] > temp; --j)   //�Աȹؼ���ǰ��������
 7             arr[j + 1] = arr[j];    //�ҵ��ȹؼ��������ֵ�����뵽�ؼ�������
 8 	arr[j + 1] = temp;     //����ؼ���
 9     }
10 }

//����������Ƚϲ����Ĵ��۱Ƚ���������Ļ������Բ��ö��ֲ��ҷ������ٱȽϲ�������Ŀ�����㷨������Ϊ�ǲ��������һ�����֣���Ϊ���ֲ��Ҳ�������
*/
