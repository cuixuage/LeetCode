#include<stdlib.h>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;

const double PRECISION = 1E-6;
const int COUNT_OF_NUMBER = 4;
const int NUMBER_TO_BE_CAL = 24;
double number[COUNT_OF_NUMBER];
string expression[COUNT_OF_NUMBER];

int cal(int a,int b,char op){
    if(op=='+') return a+b;
    else if(op=='*') return a*b;
    else if(op=='/') return b/a;  // 除与减 注意stack顺序
    else if(op=='-') return b-a;
    else return -1;
}
void int_swap(int &a,int &b,char op){
    if(op=='+' && a<b){
        int temp = a;
        a=b;
        b=temp;
    }
    else if(op=='*' && a<b){
        int temp = a;
        a=b;
        b=temp;
    }
}
bool Search(int n)
{
    /*n==1表示一次计算结束，number[0]中即为计算的结果*/
    if (n == 1)
    {
        if ( fabs(number[0] - NUMBER_TO_BE_CAL) < PRECISION )
        {
            /*expression[0]中保存了求解过程*/
            //cout << expression[0] << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a, b;          //而非double
            string expa, expb;
            a = number[i];
            b = number[j];
            /**********************************
             *将剩下的有效数字往前挪，
             *由于两数计算结果保存在number[i]中，
             *所以将数组末元素覆盖number[j]即可
             **********************************/
            number[j] = number[n - 1];
            expa = expression[i];
            expb = expression[j];
            expression[j] = expression[n - 1];
            /*计算a+b*/
            expression[i] = '(' + expa + '+' + expb + ')';
            number[i] = a + b;
            if ( Search(n - 1) ) return true;
            /*计算a-b*/
            expression[i] = '(' + expa + '-' + expb + ')';
            number[i] = a - b;
            if ( Search(n - 1) ) return true;
            /*计算b-a*/
            expression[i] = '(' + expb + '-' + expa + ')';
            number[i] = b - a;
            if ( Search(n - 1) ) return true;
            /*计算(a*b)*/
            expression[i] = '(' + expa + '*' + expb + ')';
            number[i] = a * b;
            if ( Search(n - 1) ) return true;
            /*计算(a/b)*/  //同时要求商为整数
            if (b != 0 && a%b==0)
            {
                expression[i] = '(' + expa + '/' + expb + ')';
                number[i] = a / b;
                if ( Search(n - 1) ) return true;
            }
            /*计算(b/a)*/ //同时要求商为整数
            if (a != 0 && b%a==0)
            {
                expression[i] = '(' + expb + '/' + expa + ')';
                number[i] = b / a;
                if ( Search(n - 1) ) return true;
            }
            /*恢复现场*/
            number[i] = a;
            number[j] = b;
            expression[i] = expa;
            expression[j] = expb;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < COUNT_OF_NUMBER; i++)
    {
        int x;
        cin >> x;
        number[i] = x;
        expression[i] = x+'0';
    }
    if ( !Search(COUNT_OF_NUMBER) )
    {
        cout << "No Answer" << endl;
        return 0;
    }
    string ans = expression[0];
    stack<char> mystack;
    for(char c : ans){
        if(c!='(' && c!=')'){
            mystack.push(c);
        }
        else if(c == ')' && mystack.size()!=1){
            int a=mystack.top()-'0';
            mystack.pop();
            char op = mystack.top();
            mystack.pop();
            int b=mystack.top()-'0';
            mystack.pop();
            int res = cal(a,b,op);  //得到此表达式的值
            mystack.push(res+'0');
            int_swap(a,b,op);         //加法乘法 需要操作数大值在前
            cout<<a<<op<<b<<"="<<res<<endl;
        }
    }
    return 0;
}
