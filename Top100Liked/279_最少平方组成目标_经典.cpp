#include "func.h"
/*
给定target,寻找数量最少的元素求和得到target
元素要求是平方数,e.g. 1,4,9,16....

dp[0] = 0 
dp[1] = dp[0]+1 = 1
dp[2] = dp[1]+1 = 2
dp[3] = dp[2]+1 = 3
dp[4] = Min{ dp[4-1*1]+1, dp[4-2*2]+1 } 
      = Min{ dp[3]+1, dp[0]+1 } 
      = 1				
dp[5] = Min{ dp[5-1*1]+1, dp[5-2*2]+1 } 
      = Min{ dp[4]+1, dp[1]+1 } 
      = 2
						.
						.
						.
dp[13] = Min{ dp[13-1*1]+1, dp[13-2*2]+1, dp[13-3*3]+1 } 
       = Min{ dp[12]+1, dp[9]+1, dp[4]+1 } 
       = 2
						.
						.
						.
dp[n] = Min{ dp[n - i*i] + 1 },  n - i*i >=0 && i >= 1

*/

//DP
int numSquares(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i<=n;i++){
        //对于每一个i, 由i-j*j和j*j构成  dp[i-j*j]+1
        for(int j=1;j*j<=i;j++){
            dp[i] = std::min(dp[i],dp[i-j*j] + 1);      //寻找所有组合中最小的
        }
    }
    return dp.back();
}