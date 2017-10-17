/*  stack ����Ӧ��  �Ա�638�����ݹ������һ��������
����ֻ�����ַ����ַ���'('��')'��'{'��'}'��'['��']'��ȷ�������ַ�������Ч�ġ�
���ű���ر�����ȷ��˳��"()"����"()[]{}"������Ч�ģ���"(]"��"([)]"û�С�
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

//*******************************����
int main(int argc,char** argv){
    string s = "[]{}([]{})";
    bool result = isValid(s);
    cout<< result<<endl;
    return 0;
    return 0;
}
