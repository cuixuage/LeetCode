//插入排序时间是O(n*n)
//每次当我们看到一个val小于其先前节点的节点时，我们从中head找出当前节点应该被插入的位置。
//由于可以插入节点head，所以我们创建一个new_head指向的节点head
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
    ListNode(int x)   //有参构造函数
        :val(x),next(NULL) {}
};
//画图理解
//这种题都需要一个pre结点指向头结点
ListNode * insertSortList(ListNode* head)
{
    ListNode* new_head = new ListNode(0);
    new_head -> next = head;
    ListNode* pre = new_head;
    ListNode* cur = head;
    //cur前面以及cur是已排序的链表
    while (cur)
    {
        if (cur -> next && cur -> next -> val < cur -> val)     //cur->next是较小的数值 在前面找到恰当的位置
        {
            while (pre -> next && pre -> next -> val < cur -> next -> val)  //pre从头开始寻找
                pre = pre -> next;
            /* Insert cur -> next after pre.*/    //pre->next大于等于cur->next
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;           //插入cur->next
            cur -> next = cur -> next -> next;   //原来结点cur->next移除后位置的续接
            pre -> next -> next = temp;          //插入后位置的续接
            /* Move pre back to new_head. */
            pre = new_head;
        }
        else cur = cur -> next;  //cur->next值大于cur时
    }
    ListNode* res = new_head -> next;
    delete new_head;
    return res;
}


//*************测试 排序结果
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
    //再测试输入链表为空
    test1();
    return 0;
}


/*
//将新元素取出，从左到右依次与已排序的元素比较，如果已排序的元素大于新元素，那么将该元素移动到下一个位置，接着再与前面的已排序的元素比较，直到找到已排序的元素小于等于新元素的位置，这时再将新元素插入进去
void insertion_sort(int arr[], int len)
 2 {
 3     for (int i = 1, j = 0 ; i < len; ++i)    //对比len - 1次，直到最后只剩一个数
 4     {
 5         int temp = arr[i];  //temp为关键数
 6         for (j = i - 1; j >= 0 && arr[j] > temp; --j)   //对比关键数前的所有数
 7             arr[j + 1] = arr[j];    //找到比关键数大的数值，插入到关键数后面
 8 	arr[j + 1] = temp;     //插入关键数
 9     }
10 }

//其它：如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的数目。该算法可以认为是插入排序的一个变种，称为二分查找插入排序
*/
