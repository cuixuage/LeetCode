#include "func.h"
/*
插入+删除+替换三种操作,使得单词A转化为单词B的最小编辑距离
DP[i][j] = word1[0,i)转到word[0,j)所需要的最少的转化次数

当word1[i-1]===word2[j-1]时, dp[i][j]=dp[i-1][j-1];
如果不相等: 则有三种情况
dp[i][j] = dp[i-1][j-1]+1 (替换word1[i-1]为word[j-1]的值)
dp[i][j] = dp[i-1][j]+1 (删除word1[i-1])
dp[i][j] = dp[i][j-1]+1 (将word2[j-1]插入到word2[0,i)
*/
int minDistance(string word1, string word2){
    int m = word1.size();
    int n = word2.size();
    //1.init
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
