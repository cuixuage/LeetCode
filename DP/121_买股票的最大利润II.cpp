//一次AC  
//思路:   每天售出股票的动态规划
//更新:  前面所有元素的最小值;dp数组


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==0||n==1) return 0;
    vector<int> dp(n,0);
    int min = prices[0];
    int ans = 0;
    dp[0]=0;

    for(int i=0;i<n;i++){
        if(prices[i] > prices[i-1])
            dp[i] = prices[i]-min;
        else
            dp[i] = dp[i-1];
            
        if(min > prices[i])  min = prices[i];
        if(ans < dp[i])  ans = dp[i];
    }
    return ans;
}
