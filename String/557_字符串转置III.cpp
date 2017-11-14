/* 按' '切割字符串得到的word 转置*/

#include "func.h"
 //取全部字符substr[0,string.length())  [pos, size())

string reverseWord(string s){
    stringstream ss(s);
    string temp;
    string result="";
    while(getline(ss,temp,' ')){
        std::reverse(temp.begin(),temp.end()) ;
        result +=temp+' ';
    }
    //取全部字符substr[0,string.length())  [pos, size())
    return result.substr(0,result.length()-1);
}

int main(){
    string s="Let's take LeetCode contest";
    cout<<reverseWord(s)<<endl;
    return 0;
}
