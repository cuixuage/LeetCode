/*���ڸ���str �ж����Ӵ�substring�ǻ��ĵģ�*/

//˼·������ÿһ���ַ���Ϊmid�������(ע����ż)��ʼ��������Ӵ�����
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using std::cout;
using std::endl;
using std::string;

//int count=1;   //***********count��ʼֵ��1  ��Ϊѭ������i<s.length()-1
int count=0;
void checkPalindrome(string s,int i,int j){
    while(i>=0 && j<s.length() && s.at(i)==s.at(j)){
        count++;
        i--;
        j++;
    }
}
int countSubstrings(string s){
    if(s.length() == 0) return 0;
    for(int i=0;i<=s.length()-1;i++){
        checkPalindrome(s,i,i);
        checkPalindrome(s,i,i+1);
    }
    return count;
}



//*********����
int main(int argc,char** argv){
    string s="aaa";  //expected output:6
    cout<<countSubstrings(s)<<endl;
    return 0;
}
