// http://qianyouyou.cn/2018/09/22/2018-09-22/

void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = dp[1][0] = 1;
    for(int i = 1;i<maxn;i++)
        dp[i][1] = 1;
    for(int i = 2;i<maxn;i++)
        for(int j = 1;j<=i;j++)
            dp[i][j] = dp[i][j-1] + dp[i-j][min(i-j,j)];
}