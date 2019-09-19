#include "func.h"

//  仔细考虑 '*'的三种情况
bool matchCore(char* str,char* pattern){
    if(*str=='\0' && *pattern=='\0')    return true;
    if(*str!='\0' && *pattern=='\0')    return false;
    if(*(pattern+1) == '*'){
        if(*str==*pattern || (*pattern=='.'&&*str!='\0'))
            return matchCore(str+1,pattern+2) || //1. *只匹配str1个字符
                   matchCore(str+1,pattern) ||   //2. *匹配str多个字符,pattern不移动
                   matchCore(str,pattern+2);     //3. *匹配0个字符（主动放弃）
        else
            return matchCore(str,pattern+2); //4. str patter字符不同,(*表达匹配0次 )
    }
    if(*str==*pattern || (*pattern=='.'&&*str!='\0'))
        return matchCore(str+1,pattern+1);                  //逐个匹配
}

bool match(char* str, char* pattern){
    if (str==NULL || pattern==NULL) return false;
    return matchCore(str,pattern);
}


//dp
// https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation