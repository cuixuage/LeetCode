class Queue
{
    stack<int> input, output;
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        input.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        peek();   //这里调用peek函数，不取返回值
        output.pop();   //queue的删除，再使用stack的pop

    }

    // Get the front element.
    int peek(void)
    {
        if (output.empty())
            while (input.size())   //input stack保存到output stack 此时输出output实现了先进先出
                output.push(input.top()), input.pop();   //input加一个删一个
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return input.empty() && output.empty();

    }
};
