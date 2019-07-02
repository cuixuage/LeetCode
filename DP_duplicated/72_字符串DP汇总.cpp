#include "func.h"
/*
单词1word 1th到ith
单词2word 1th到jth  这两个子序列的最短编辑距离

dp[i][j] = min(dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1)
*/

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    //1.init  (非常重要   矩阵的边界值)
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
        dp[i][0] = i;
    for(int j=1;j<=n;j++)
        dp[0][j] = j;
    //2.dp
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = std::min(dp[i-1][j-1]+1,std::min(dp[i][j-1]+1,
                dp[i-1][j]+1) );
        }
    }
    return dp[m][n];
}

//DP 最长公共子串(连续的)
dp[i][j] = dp[i-1][j-1] + 1   (i,j字符相等)
dp[i][j] = 0

//DP 最长公共子序列(非连续的)
dp[i][j] = dp[i-1][j-1] + 1   (i,j字符相等)
dp[i][j] = max(dp[i-1][j] , dp[i-1][j])