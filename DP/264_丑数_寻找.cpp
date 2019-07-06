/*
丑数: 仅由2,3,5三种数字乘积得到
丑数: 由另外一个丑数乘以这三种数字得到
dp[i] = min(dp[n]*2,dp[m]*3,dp[l]*5)
n,m,l是三个自增的指针。

F(m) = min(F(i)*2,min(F(j)*3,F(k)5)) 
返回第n个丑数
*/
#include "func.h"
int nthUglyNumber(int Kth){       //第k个丑数
    if(Kth<=0) return 0;
    if(Kth==1) return 1;
    int n=0,m=0,l=0;
    vector<int> dp(Kth,0);
    dp[0] = 1;             // init
    for(int i=1;i<Kth;i++){
        dp[i] = std::min(dp[n]*2,std::min(dp[m]*3,dp[l]*5));
        if(dp[i] == dp[n]*2) n++;
        if(dp[i] == dp[m]*3) m++;               //dp[因子使用次数] * 因子
        if(dp[i] == dp[l]*5) l++;
    }
    return dp[Kth-1];
}