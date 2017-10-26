/*
stack1 ��������Ԫ��
stack2 ���浱ǰ��СԪ��
pop: if(!s2.empty() && s2.top()==s1.top()) s2.pop(); ��ɾ��s1.top()
push��s1.push() ; if(s2.empty() || x<=s2.top()) s2.push(x);������С�ڵ���
*/


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
    if(s2.empty() || x<=s2.top()) s2.push(x);    //s2.top������Сֵ    //�ر���Ҫע��������*******С�ڵ���*****����С��
}

void MinStack::pop(){
    if(!s2.empty() && s2.top()==s1.top()) s2.pop();    //ɾ��������Сֵ
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
