/*寻找最长的substring   substr为回文序列
对比647题 寻找所有的回文子串
*/

//注: 1.substring(截取的连续字符)而非sequence(子序列)
//    2.结果可能有多个

#include"func.h"

int lo=0,maxlen=0;      //lo记录子串起始点
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
    for(int i=0;i<=len-1;i++){   // 小于len-1
        //子串从i向左右扩展;以i为中心向两侧扩展;
        checkPalindrome(s,i,i);
        checkPalindrome(s,i,i+1);
    }
    return s.substr(lo,maxlen);   //注:substr(start,num) => 截取[start,start+num)
}


int main(int argc,char* argv){
    string test="cbbd";
    cout<<longestPalindrome(test)<<endl;
    cout<<lo<<" "<<maxlen<<endl;
    return 0;
}
