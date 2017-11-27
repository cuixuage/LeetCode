/*ֻ�����зǸ�����  + - * /�Լ��ո��ַ� ����ans*/
/*
����:2 -3-5/2  return -1
˼·:stack (+2) (-3) (-5)  pop push(-5/2)
�ٰ�����ֵ����������
��Ҫ���ж� ���������Ҳ�����������
*/

#include"func.h"

int calculate(string s){
    int len=s.length();
    if(s=="" || len==0) return 0;
    stack<int> mystack ;
    int num=0;
    char sign = '+';   //��ʼֵ ����һ�����ֵ�digit�����Ҳ����������������stack
    for(int i=0;i<len;i++){
        if(isdigit(s.at(i))){   //�Ҳ�����
            num = num*10 + s.at(i)-'0';
        }
        //stack�洢sign���������
        if((!isdigit(s.at(i)) && ' '!=s.at(i) )|| i==len-1){  //����ֻ��ֻ��һ��������û�м���stack���
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
            //���²�����
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
