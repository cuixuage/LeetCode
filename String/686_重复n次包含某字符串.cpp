/*
�ַ���A�����ظ�num��ʹ��B��ΪA���Ӵ�;������num�򷵻�-1;
˼·:
1.A�ĳ�������Ҫ����B
a��"abc" "abc" "abc"
b��"c abc a"- ����������£�������Ȼ��Ҫb.len / a.len+2
*/

#include<iostream>
#include<string>
#include<string.h>
using std::string;
using std::cout;
using std::endl;

//ע: B.length()/A.length()+1 �ǵ�һ�� A.length > B.length
int repeatedStringMatch(string A, string B) {
    string temp = A;

    for(int i=1;i<=B.length()/A.length()+2;i++){    //��ʼA����һ�� ����i=1��ʼֵ
        if(temp.find(B) != string::npos) return i;

        temp +=A;   //�ַ����ظ�һ�� (���: �Ӻ���appendҲ�൱����string.begin�ظ� �ǵȼ۵�)
    }
    return -1;    //���� B.length()/A.length()+2������ζ����Զ����contain B
}


//*****************����
int main(int argc,char** argv){
    string A="abc";
    string B="cabca";

    cout<<repeatedStringMatch(A,B)<<endl;
    return 0;
}
