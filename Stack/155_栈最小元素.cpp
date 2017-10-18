/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

����1:   ��ϸ˼��Ϊʲôʹ������stack
stack2�ж�̬�滮��˼�룿����
*******************************(s2.pop �Ժ��s2.top()��Ȼ����Сֵ)

����2:
ֻʹ��һ��ջ��java����
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
    stack<int> s1;   //��������Ԫ��
    stack<int> s2;   //top�洢��Сֵ
};

MinStack::MinStack(){}

void MinStack::push(int x){
    s1.push(x);
    //�ر���Ҫע��������*******С�ڵ���*****����С��
    if(s2.empty() || x<=s2.top()) s2.push(x);    //s2.top������Сֵ    //�ر���Ҫע��������*******С�ڵ���*****����С��
}

void MinStack::pop(){
    if(!s2.empty() && s2.top()==s1.top()) s2.pop();   //ɾ��s1ʱע�⿼��s2
    s1.pop();
}

int MinStack::top(){
    return s1.top();
}

int MinStack::getMin(){
     if(!s2.empty())return s2.top();
}

//*****************����
int main(int argc,char** argv){

    //MinStack mst();    //��������������� .
    MinStack *mst = new MinStack ();
    mst->push(0);
    mst->push(-5);
    mst->push(-10);    //��������: ���s2.push()�ж���䲻��<=  ��ô������Сֵ��-5
    mst->push(-10);
    mst->pop();

    cout<<mst->top()<<" "<<mst->getMin()<<endl;
    return 0;
}
