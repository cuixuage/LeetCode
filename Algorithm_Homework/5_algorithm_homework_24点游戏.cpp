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
    else if(op=='/') return b/a;  // ����� ע��stack˳��
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
    /*n==1��ʾһ�μ��������number[0]�м�Ϊ����Ľ��*/
    if (n == 1)
    {
        if ( fabs(number[0] - NUMBER_TO_BE_CAL) < PRECISION )
        {
            /*expression[0]�б�����������*/
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
            int a, b;          //����double
            string expa, expb;
            a = number[i];
            b = number[j];
            /**********************************
             *��ʣ�µ���Ч������ǰŲ��
             *��������������������number[i]�У�
             *���Խ�����ĩԪ�ظ���number[j]����
             **********************************/
            number[j] = number[n - 1];
            expa = expression[i];
            expb = expression[j];
            expression[j] = expression[n - 1];
            /*����a+b*/
            expression[i] = '(' + expa + '+' + expb + ')';
            number[i] = a + b;
            if ( Search(n - 1) ) return true;
            /*����a-b*/
            expression[i] = '(' + expa + '-' + expb + ')';
            number[i] = a - b;
            if ( Search(n - 1) ) return true;
            /*����b-a*/
            expression[i] = '(' + expb + '-' + expa + ')';
            number[i] = b - a;
            if ( Search(n - 1) ) return true;
            /*����(a*b)*/
            expression[i] = '(' + expa + '*' + expb + ')';
            number[i] = a * b;
            if ( Search(n - 1) ) return true;
            /*����(a/b)*/  //ͬʱҪ����Ϊ����
            if (b != 0 && a%b==0)
            {
                expression[i] = '(' + expa + '/' + expb + ')';
                number[i] = a / b;
                if ( Search(n - 1) ) return true;
            }
            /*����(b/a)*/ //ͬʱҪ����Ϊ����
            if (a != 0 && b%a==0)
            {
                expression[i] = '(' + expb + '/' + expa + ')';
                number[i] = b / a;
                if ( Search(n - 1) ) return true;
            }
            /*�ָ��ֳ�*/
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
            int res = cal(a,b,op);  //�õ��˱��ʽ��ֵ
            mystack.push(res+'0');
            int_swap(a,b,op);         //�ӷ��˷� ��Ҫ��������ֵ��ǰ
            cout<<a<<op<<b<<"="<<res<<endl;
        }
    }
    return 0;
}
