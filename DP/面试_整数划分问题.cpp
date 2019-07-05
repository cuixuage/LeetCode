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

// https://www.cnblogs.com/xiaoxian1369/archive/2011/09/12/2174212.html
// 　　1. 将n划分成若干正整数之和的划分数。
// 　　2. 将n划分成k个正整数之和的划分数。
// 　　3. 将n划分成最大数不超过k的划分数。
// 　　4. 将n划分成若干奇正整数之和的划分数。
// 　　5. 将n划分成若干不同整数之和的划分数。