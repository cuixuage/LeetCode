/*只包含有非负整数  + - * /以及空格字符 计算ans*/
/*
例如:2 -3-5/2  return -1
思路:stack (+2) (-3) (-5)  pop push(-5/2)
再把所有值加起来即可
主要是判断 操作符和右操作数？？？
*/

#include"func.h"

int calculate(string s){
    int len=s.length();
    if(s=="" || len==0) return 0;
    stack<int> mystack ;
    int num=0;
    char sign = '+';   //初始值 将第一个出现的digit当做右操作数并将结果存入stack
    for(int i=0;i<len;i++){
        if(isdigit(s.at(i))){   //右操作数
            num = num*10 + s.at(i)-'0';
        }
        //stack存储sign的左操作数
        if((!isdigit(s.at(i)) && ' '!=s.at(i) )|| i==len-1){  //避免只有只有一个整数而没有加入stack情况
            if(sign=='-')
                mystack.push(-num);
            if(sign=='+')
                mystack.push(num);
            if(sign=='*'){
                int temp=mystack.top();
                mystack.pop();
                mystack.push(temp*num);
            }
            if(sign=='/'){
                int temp=mystack.top();
                mystack.pop();
                mystack.push(temp/num);
            }
            //更新操作符
            sign=s.at(i);
            num=0;
        }
    }
    int res=0;
    while(!mystack.empty()){
        res += mystack.top();
        mystack.pop();
    }
    return res;
}

int main(){
    string s= " 3 +5/ 2";
    cout<<calculate(s)<<endl;
    return 0;
}
