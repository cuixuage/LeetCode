/*���ɾ��һ���ַ����жϴ��ַ����Ƿ���ܹ���Ϊ�����ַ���*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using std::cout;
using std::endl;
using std::string;

//����1: ��0��ʼ����ÿһ��ɾ���ַ����Ƿ��ܹ���ɻ���
//��ʱ

//����2: ̰��
//��������s[i]...s[j]  ���If s[i] == s[j] then we may take i++; j--
//����ֻ���ж�s[i+1], s[i+2], ..., s[j] or s[i], s[i+1], ..., s[j-1]�Ƿ�Ϊ�������У���ʱ��Ȼ��ɾ����ǰ����s[i] ����s[j]��

bool isPalindromeRange(string s,int i,int j){
    for(int k=i; k<=i+(j-i)/2; k++)
        if(s.at(k) != s.at(j-(k-i))) return false;
    return true;
}

bool validPalindrome(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s.at(i)!=s.at(s.length()-1-i)){   //���ɾ��һ���ַ�  ����ɾ��s[i] ����s[length-i-1]
            int j = s.length()-i-1;
            return (isPalindromeRange(s,i+1,j) ||
                    isPalindromeRange(s,i,j-1));
        }
        //If s[i] == s[j] then we may take i++; j--  ���ж���Ȧ�Ƿ���ϻ����ַ���Ҫ��
        else continue;
    }
    return true;
}

//*******************����
int main(int argc,char** argv){
    string s="aadcaa";
    cout<<validPalindrome(s)<<endl;
    return 0;
}
