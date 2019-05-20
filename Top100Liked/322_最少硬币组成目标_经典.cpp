/*
给定一组硬币,判断硬币最少使用数量 (每一种的硬币,可重复使用硬币) 能否构成terget值
思路1:
target按硬币最大值不断取余(错误)

思路2:  DP
c 硬币的币值
dp存储target,最少需要的的硬币数量
dp[i] = min(dp[i],dp[i-c]+1)
如果i-c>=0 && dp[i-c]!=-1,则表示存在'i-c'的解

解题思路:
硬币种类数组
0,target的递推数组

*/
#include "func.h"

int coinChange(vector<int>& coins,int amount){
    vector<int> dp(amount+1,-1);        //初始化为-1
    dp[0] = 0;
    for(int i=1; i<= amount; ++i)
        for(auto& c : coins)
            if(i-c>=0 && dp[i-c]!=-1)       //dp[i]可以通过前面的某一个dp+c构成
                dp[i]=dp[i]>0 ? std::min(dp[i],dp[i-c]+1) : dp[i-c]+1;
    return dp[amount];
}