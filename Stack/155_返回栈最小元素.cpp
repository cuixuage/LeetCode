/*
stack1 保存所有元素
stack2 保存当前最小元素
pop: if(!s2.empty() && s2.top()==s1.top()) s2.pop(); 再删除s1.top()
push：s1.push() ; if(s2.empty() || x<=s2.top()) s2.push(x);这里是小于等于
*/


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
    if(s2.empty() || x<=s2.top()) s2.push(x);    //s2.top保存最小值    //特别需要注意这里是*******小于等于*****而非小于
}

void MinStack::pop(){
    if(!s2.empty() && s2.top()==s1.top()) s2.pop();    //删除的是最小值
    s1.pop();
}

int MinStack::top(){
    return s1.top();
}

int MinStack::getMin(){
     if(!s2.empty())return s2.top();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
