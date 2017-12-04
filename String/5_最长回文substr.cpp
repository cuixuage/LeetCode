/*Ѱ�����substring   substrΪ��������
�Ա�647�� Ѱ�����еĻ����Ӵ�
*/

//ע: 1.substring(��ȡ�������ַ�)����sequence(������)
//    2.��������ж��

#include"func.h"

int lo=0,maxlen=0;      //lo��¼�Ӵ���ʼ��
void checkPalindrome(const string& s,int i,int j){
    while(i>=0 && j<s.length() && s.at(i)==s.at(j)){
        --i;
        ++j;
    }
    if(maxlen < j-i-1){
        lo = i+1;
        maxlen = j-i-1;
        cout<<"max:"<<maxlen<<endl;
    }
}
string longestPalindrome(string s) {
    int len = s.length();
    if(len<2) return s;
    for(int i=0;i<=len-1;i++){   // С��len-1
        //�Ӵ���i��������չ;��iΪ������������չ;
        checkPalindrome(s,i,i);
        checkPalindrome(s,i,i+1);
    }
    return s.substr(lo,maxlen);   //ע:substr(start,num) => ��ȡ[start,start+num)
}


int main(int argc,char* argv){
    string test="cbbd";
    cout<<longestPalindrome(test)<<endl;
    cout<<lo<<" "<<maxlen<<endl;
    return 0;
}
