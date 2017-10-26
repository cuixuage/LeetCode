/*
�沨�����ʽ��ֵ stack�������� ����ǲ�����pop()���μ������push
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cstdlib>
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::stack;
int evalRPN(vector<string>& Elements){
    stack<int> answer;
    for(string str : Elements){
        //***********ע��else if ��if����
        //�������else if���һ��else Ĭ��ֻƥ�����һ��if
        if(str=="+"){
            int a = answer.top();
            answer.pop();
            int b = answer.top();
            answer.pop();
            answer.push(b + a);
        }
        else if(str=="-"){
            int a = answer.top();
            answer.pop();
            int b = answer.top();
            answer.pop();
            answer.push(b - a);    //�ر�ע��: "-" "/"��������˳�� (stack�Ƚ����)
        }
        else if(str=="*"){
            int a = answer.top();
            answer.pop();
            int b = answer.top();
            answer.pop();
            answer.push(b * a);
        }
        else if(str=="/"){
            int a = answer.top();
            answer.pop();
            int b = answer.top();
            answer.pop();
            answer.push(b / a);     //�ر�ע��: "-" "/"��������˳�� (stack�Ƚ����)
        }
        else{     //�������ǲ�����ʱ
            int temp = std::atoi(str.c_str());
            answer.push(temp);
        }
    }
    return answer.top();
}

//**************************����
int main(int argc,char** argv){
    string temp[] = {"2", "1", "+", "3", "*"};
    vector<string> Elements(temp,temp+5);
    cout<< evalRPN(Elements)<<endl;
    return 0;
}
