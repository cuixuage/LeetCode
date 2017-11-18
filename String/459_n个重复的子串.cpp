/*对于全部是小写字母的string来说 是否存在一个子串str
使得N个重复的str 构成原有的string*/

#include "func.h"
/*
1.子串的长度需要是string的除数
2.计算重复次数n
3.n次重复的子串 是否equals(string)?
*/
bool repeatSubstringingPattern(string str){
    int strlen = str.length();
    //倒序寻找更迅速
    for(int i=strlen/2;i>=1;i--){
        string temp;
        if(strlen%i == 0){ //子串长度被整除
            int n=strlen/i;
            string token = str.substr(0,i);
            for(int j=0;j<n;j++)
                temp += token;
        }
        if(temp == str) return true;
    }
    return false;
}

int main(){
    string s1="abab";
    string s2="aba";
    cout<<repeatSubstringingPattern(s1)<<endl;
    cout<<repeatSubstringingPattern(s2)<<endl;
    return 0;
}
