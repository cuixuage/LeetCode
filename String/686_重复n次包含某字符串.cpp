/*
字符串A最少重复num次使得B成为A的子串;不存在num则返回-1;
思路:
1.A的长度首先要大于B
a："abc" "abc" "abc"
b："c abc a"- 在这种情况下，我们仍然需要b.len / a.len+2
*/

#include<iostream>
#include<string>
#include<string.h>
using std::string;
using std::cout;
using std::endl;

//注: B.length()/A.length()+1 是第一次 A.length > B.length
int repeatedStringMatch(string A, string B) {
    string temp = A;

    for(int i=1;i<=B.length()/A.length()+2;i++){    //起始A就是一份 所以i=1起始值
        if(temp.find(B) != string::npos) return i;

        temp +=A;   //字符串重复一次 (理解: 从后面append也相当于在string.begin重复 是等价的)
    }
    return -1;    //超过 B.length()/A.length()+2次数意味着永远不会contain B
}


//*****************测试
int main(int argc,char** argv){
    string A="abc";
    string B="cabca";

    cout<<repeatedStringMatch(A,B)<<endl;
    return 0;
}
