/*
�����ַ��� ÿ2k���ַ���תǰk�������ʣ���ַ�����С��k ��ȫ����ת������kС��2k��תǰk��
   ÿ2*k��Ԫ�� ǰk��Ԫ��ת��
*/

#include "func.h"
//**********************һ��AC
//����reverse
string reverseStr(string s, int k) {
    int len = s.length();
    int n=len/2/k;                     //�ж��ٸ�2*k
    int m=len%(2*k);                   //�����Ƕ���
    int n1=n;
    while(n1--){                       //ÿ2*k��Ԫ�� ǰk��Ԫ��ת��
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
