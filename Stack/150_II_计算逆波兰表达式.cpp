#include "func.h"
int evalRPN(vector<string>& Elements){
    stack<int> answer;
    int a,b=0;
    for(string str:Elements){
        if(str=="+" || str=="-" || str=="*" || str=="/"){
            a = answer.top();
            answer.pop();
            b = answer.top();
            answer.pop();
        }
        if(str == "+"){
            answer.push(b+a);
        }
        else if(str == "-"){
            answer.push(b-a);
        }
        else if(str == "*"){
            answer.push(b*a);
        }
        else if(str == "/"){
            answer.push(b/a);
        }else{
            //数字
            int tmp = std::atoi(str.c_str());
            answer.push(tmp);
        }
    }
    return answer.top();
}
