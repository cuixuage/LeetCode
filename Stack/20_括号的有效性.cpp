/*  stack 典型应用  对比638函数递归调用有一定相似性
由于只包含字符的字符串'('，')'，'{'，'}'，'['和']'，确定输入字符串是有效的。
括号必须关闭以正确的顺序，"()"并且"()[]{}"都是有效的，但"(]"并"([)]"没有。
*/

#include<iostream>
#include<stack>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::stack;

bool isValid(string s){
    stack<char> stack_char;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') stack_char.push(s[i]);
        else if(s[i]==')' && !stack_char.empty() && stack_char.top()=='(') stack_char.pop();
        else if(s[i]==']' && !stack_char.empty() && stack_char.top()=='[') stack_char.pop();
        else if(s[i]=='}' && !stack_char.empty() && stack_char.top()=='{') stack_char.pop();
        else return false;
    }
//    if(stack_char.empty()) return true;
//    else return false;
    return stack_char.empty();
}

//*******************************测试
int main(int argc,char** argv){
    string s = "[]{}([]{})";
    bool result = isValid(s);
    cout<< result<<endl;
    return 0;
    return 0;
}
