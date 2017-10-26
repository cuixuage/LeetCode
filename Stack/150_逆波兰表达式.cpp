/*
逆波兰表达式求值 stack保存整数 如果是操作符pop()两次计算后再push
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
        //***********注意else if 和if区别
        //如果不是else if最后一个else 默认只匹配最后一个if
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
            answer.push(b - a);    //特别注意: "-" "/"操作符的顺序 (stack先进后出)
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
            answer.push(b / a);     //特别注意: "-" "/"操作符的顺序 (stack先进后出)
        }
        else{     //整数而非操作符时
            int temp = std::atoi(str.c_str());
            answer.push(temp);
        }
    }
    return answer.top();
}

//**************************测试
int main(int argc,char** argv){
    string temp[] = {"2", "1", "+", "3", "*"};
    vector<string> Elements(temp,temp+5);
    cout<< evalRPN(Elements)<<endl;
    return 0;
}
