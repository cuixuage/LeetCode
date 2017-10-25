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
        peek();   //�������peek��������ȡ����ֵ
        output.pop();   //queue��ɾ������ʹ��stack��pop

    }

    // Get the front element.
    int peek(void)
    {
        if (output.empty())
            while (input.size())   //input stack���浽output stack ��ʱ���outputʵ�����Ƚ��ȳ�
                output.push(input.top()), input.pop();   //input��һ��ɾһ��
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return input.empty() && output.empty();

    }
};
