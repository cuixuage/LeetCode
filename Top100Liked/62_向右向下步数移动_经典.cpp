
#include "func.h"
/*
经典DP 每次只能往下或者往右走一步,共有多少种解法
DP[i][j] = dp[i-1][j] + dp[j][i-1]
*/
int uniquePaths(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n,0));     //2d vector init
    // dp[1][0] = 1;
    // dp[0][1] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //初始化边缘元素
            if(i==0 || j==0) dp[i][j]=1;
            //关键 从上到下,从左到右计算
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];    
        }
    }
    return dp[m-1][n-1];
}