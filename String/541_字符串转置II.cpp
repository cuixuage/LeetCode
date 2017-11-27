/*
给定字符串 每2k个字符反转前k个。如果剩余字符数字小于k 则全部翻转；大于k小于2k反转前k个
   每2*k个元素 前k个元素转置
*/

#include "func.h"
//**********************一次AC
//善用reverse
string reverseStr(string s, int k) {
    int len = s.length();
    int n=len/2/k;                     //有多少个2*k
    int m=len%(2*k);                   //余数是多少
    int n1=n;
    while(n1--){                       //每2*k个元素 前k个元素转置
        int start=n1*2*k;
        int end=n1*2*k+k;
        std::reverse(s.begin()+start,s.begin()+end);
    }
    if(m<k) std::reverse(s.begin()+n*2*k,s.begin()+n*2*k+m);
    if(m>=k && m<2*k) std::reverse(s.begin()+n*2*k,s.begin()+n*2*k+k);
    return s;

    }
int main(){
    string s="abcdefg";
    cout<<reverseStr(s,2)<<endl;
    return 0;
}
