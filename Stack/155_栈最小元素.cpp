/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

方法1:   仔细思考为什么使用两个stack
stack2有动态规划的思想？？？
*******************************(s2.pop 以后的s2.top()仍然是最小值)

方法2:
只使用一个栈的java方法
https://leetcode.com/problems/min-stack/discuss/

*/
#include<iostream>
#include<stack>
using std::cout;
using std::endl;
using std::stack;

class MinStack{
public:
    MinStack();
    void push(int);
    void pop();
    int top();
    int getMin();
private:
    stack<int> s1;   //保存所有元素
    stack<int> s2;   //top存储最小值
};

MinStack::MinStack(){}

void MinStack::push(int x){
    s1.push(x);
    //特别需要注意这里是*******小于等于*****而非小于
    if(s2.empty() || x<=s2.top()) s2.push(x);    //s2.top保存最小值    //特别需要注意这里是*******小于等于*****而非小于
}

void MinStack::pop(){
    if(!s2.empty() && s2.top()==s1.top()) s2.pop();   //删除s1时注意考虑s2
    s1.pop();
}

int MinStack::top(){
    return s1.top();
}

int MinStack::getMin(){
     if(!s2.empty())return s2.top();
}

//*****************测试
int main(int argc,char** argv){

    //MinStack mst();    //对象类属性运算符 .
    MinStack *mst = new MinStack ();
    mst->push(0);
    mst->push(-5);
    mst->push(-10);    //测试样例: 如果s2.push()判断语句不是<=  那么后面最小值是-5
    mst->push(-10);
    mst->pop();

    cout<<mst->top()<<" "<<mst->getMin()<<endl;
    return 0;
}
