#include "func.h"
/*
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
思路:
3-loop 判断4份string是否都是有效的IP字段
*/
vector<string> restoreIpAddresses(string s){
    vector<string> res;
    int len = s.length();
    for(int i=1; i<4&&i<len-2; i++){
        for(int j=i+1; j<i+4&&j<len-1; j++){
            for(int k=j+1; k<j+4&&k<len;k++){
                //substr左闭起始位置,右是字符个数 [)
                string s1 = s.substr(0,i);
                string s2 = s.substr(i,j-i);
                string s3 = s.substr(j,k-j);
                string s4 = s.substr(k,len-k);      //切割位置
                if(isValid(s1) && isValid(s2) &&isValid(s3) &&isValid(s4))
                    res.push_back(s1+"."+s2+"."+s3+"."+s4);
            }
        }
    }
    return res;
}

bool isValid(string s){
    if (s.length()>3 || s.length()==0 || (s[0]=='0' && s.length()>1)
        || std::atoi(s.c_str())>255)
        return false;
    else
        return true;
}
