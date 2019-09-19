//DP
1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
3, If p.charAt(j) == '*': 
   here are two sub conditions:
               1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
               2   if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
                              dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
                           or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty

public boolean isMatch(String s, String p) {

    if (s == null || p == null) {
        return false;
    }
    boolean[][] dp = new boolean[s.length()+1][p.length()+1];
    dp[0][0] = true;
    for (int i = 0; i < p.length(); i++) {
        if (p.charAt(i) == '*' && dp[0][i-1]) {
            dp[0][i+1] = true;
        }
    }
    for (int i = 0 ; i < s.length(); i++) {
        for (int j = 0; j < p.length(); j++) {
            if (p.charAt(j) == '.') {
                dp[i+1][j+1] = dp[i][j];
            }
            if (p.charAt(j) == s.charAt(i)) {
                dp[i+1][j+1] = dp[i][j];
            }
            if (p.charAt(j) == '*') {
                if (p.charAt(j-1) != s.charAt(i) && p.charAt(j-1) != '.') {
                    dp[i+1][j+1] = dp[i+1][j-1];
                } else {
                    dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                }
            }
        }
    }
    return dp[s.length()][p.length()];
}

 /*
 递归思路:
 1.假如不存在*, 需要逐个判断pattern,string
 2. * 代表其前面的字符出现0次,或者多次
 */
#include "func.h"
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