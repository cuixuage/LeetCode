/*
方法1:遍历所有链表将其val保存到数组中,sort数组,再由val构造出新的链表
方法2：k个链表逐个排序比较
方法3:每两条链表合并一次
方法4:优先队列 _优先队列自动排序？ 重写compare方法
*/
#include<iostream>
#include<vector>
#include<limits>
using std::cout;
using std::endl;
using std::vector;

class ListNode {
public:
    int val;
    ListNode *next;
public:
    ListNode():val(0),next(NULL) {}
    ListNode(int x)  :val(x),next(NULL) {}
};
//************************merge两条sorted的链表
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* prev=new ListNode(INT_MIN);
    ListNode* temp=prev;
    while(l1&&l2){
        if(l1->val < l2->val){   //升序排列
            temp->next=l1;
            l1=l1->next;
        }
        else{
            temp->next=l2;
            l2=l2->next;
        }
        temp=temp->next;
    }
    temp->next=l1?l1:l2;  //优雅 l1或者l2不等长时 此时必有一个为空
    return prev->next;
}
//************************merge 多条sorted的链表
ListNode* mergeKLists(vector<ListNode*> &lists){ //使用引用 特别是出现容器迭代器时候
    if(lists.empty()) return NULL;
    while(lists.size()>1){
        lists.push_back(mergeTwoLists(lists[0],lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    //return lists.front();
    return lists[0];
}

int main(int argc,char** argv){

}
