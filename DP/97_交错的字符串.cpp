/*
判断string3是不是可以被s1,s2交错组成？
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

字符串3能否被组成 dp[i][j] = 
*/

#include "func.h"
bool isInterleave(string s1, string s2, string s3){
    if(s1.size()+s2.size() != s3.size()) 
        return false;
    //1. init
    vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,false));
    for(int i=0; i<s1.size()+1;i++){
        for(int j=0; j<s2.size()+1;j++){
            if(i==0 && j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            else if(j==0)
                dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
        }
    }
    //2. dp
    for(int i=1; i<s1.size()+1;i++){
        for(int j=1; j<s2.size()+1;j++)
            dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) ||
                        (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
    }
    return dp[s1.size()][s2.size()];
}
