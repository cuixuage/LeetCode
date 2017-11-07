/*最多删除一个字符，判断此字符串是否会能够成为回文字符串*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using std::cout;
using std::endl;
using std::string;

//方案1: 从0开始尝试每一个删除字符，是否能够组成回文
//超时

//方案2: 贪心
//对于序列s[i]...s[j]  如果If s[i] == s[j] then we may take i++; j--
//否则只需判断s[i+1], s[i+2], ..., s[j] or s[i], s[i+1], ..., s[j-1]是否为回文序列（此时必然是删除当前序列s[i] 或者s[j]）

bool isPalindromeRange(string s,int i,int j){
    for(int k=i; k<=i+(j-i)/2; k++)
        if(s.at(k) != s.at(j-(k-i))) return false;
    return true;
}

bool validPalindrome(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s.at(i)!=s.at(s.length()-1-i)){   //最多删除一个字符  尝试删除s[i] 或者s[length-i-1]
            int j = s.length()-i-1;
            return (isPalindromeRange(s,i+1,j) ||
                    isPalindromeRange(s,i,j-1));
        }
        //If s[i] == s[j] then we may take i++; j--  即判断内圈是否符合回文字符串要求
        else continue;
    }
    return true;
}

//*******************测试
int main(int argc,char** argv){
    string s="aadcaa";
    cout<<validPalindrome(s)<<endl;
    return 0;
}
