#include "func.h"
/*
给定一个入栈的序列，判断是不是可以构成出栈的序列
思路:
不断的入栈,直到入栈的栈顶==出栈的头部元素时，出栈。 继续判断,如果入栈的队列最后不为空 
则不能构成出栈序列
条件:   无重复的元素
*/

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int index = 0;  
    stack<int> push_pop;
    for(auto i:pushed){
        push_pop.push(i);
        while(!push_pop.empty() && push_pop.top() == popped[index]){
            //寻找出栈的元素
            push_pop.pop();
            index ++;
        }
    }
    return push_pop.size()==0?1:0;
}