#include "func.h"
/*
m*n的棋盘,从左上到右下,一共有多少种走法？
（只能向下或者向右）
*/

//n 行 m列
//dp[i][j] = dp[i-1][j] + dp[i][j-1]
int uniquePaths(int m,int n){
    //init 边界
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(i==0 || j==0) dp[i][j] = 1;
    }
    //dp
    for(int i=1;i<n;i++){
        for (int j=1;j<m;j++)
            dp[i][j]  = dp[i-1][j] + dp[i][j-1];
    }
    return dp[n-1][m-1];
}