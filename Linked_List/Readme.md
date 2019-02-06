Leetcode 链表题目
C++
一共25道题目
completed time at 2017/10/14

```cpp
/*
指针和引用的区别？
指针会新构建一个变量,而引用则不会
e.g.
int* p;
void func(int* p1){};
在指针传递中,实参是p,形参是p1这是两个不同的变量。
1.可以通过修改p1指向的变量,来改变p指向的变量
2.修改p1的值,不会改变p的值,即*p1不会改变
*/

#include<iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode()    :val(0),next(NULL) {}
    ListNode(int x)    :val(x),next(NULL) {}
};

void func(ListNode* p){
    p = p->next;
    cout<<p->val<<endl;
}

void func2(ListNode*& p){       //指针变量的引用 可以成功修改
    p = p->next;
    cout<<p->val<<endl;
}

int main(){
    ListNode arr[3]={0};
    for(int i=0;i<2;i++){
        arr[i].val = i+1;
        arr[i].next = &arr[i+1];
    }
    arr[2].val = 3;
    arr[2].next = NULL;
    ListNode* p = &arr[0];
    cout<<p->val<<endl;
    func(p);
    cout<<p->val<<endl;
}
```