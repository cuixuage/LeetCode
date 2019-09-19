/*
仅包含数字的字符串,有多少种可能性解密？

dp[0] = 1 空字符串
dp[1] 仅有一个字符时的解密可能性
*/

#include"func.h"
int numDecodings(string str){
    if(str=="" || str.size()==0) return 0;
    int N = str.size();
    vector<int> dp(N+1,0);
    dp[0] = 1;
    dp[1] = (str[0]=='0')?0:1;
    for(int i=2;i<=N;i++){
        int first = atoi(str.substr(i-1,1).c_str());
        int second = atoi(str.substr(i-2,2).c_str());
        if(first >=1 && first <= 9) dp[i] += dp[i-1];
        if(second >= 10 && second <= 26) dp[i] += dp[i-2];
    }
    return dp[N];
}