/* ��' '�и��ַ����õ���word ת��*/

#include "func.h"
 //ȡȫ���ַ�substr[0,string.length())  [pos, size())

string reverseWord(string s){
    stringstream ss(s);
    string temp;
    string result="";
    while(getline(ss,temp,' ')){
        std::reverse(temp.begin(),temp.end()) ;
        result +=temp+' ';
    }
    //ȡȫ���ַ�substr[0,string.length())  [pos, size())
    return result.substr(0,result.length()-1);
}

int main(){
    string s="Let's take LeetCode contest";
    cout<<reverseWord(s)<<endl;
    return 0;
}
