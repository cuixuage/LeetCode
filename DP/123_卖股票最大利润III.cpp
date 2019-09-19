//在122题目的基础上  增加限制交易次数为两次


//正确思路:   再进行理解~~~~   现在不是很明白
//递推公式:  dp[k,i] = max(dp[k,i-1],  prices[i]-prices[j]+dp[k-1,j-1]), j=[0..i-1]
//k是第k次交易 第i天
//如果不交易 等于前一天的利润
//第i天卖出 那么利润是prices[i]-prices[i-1]+dp[i-1,j-1] 上回合交易的+前一天

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution

#include "func.h"
int maxProfit(vector<int> &prices) {
    // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
    // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
    //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
    // f[0, ii] = 0; 0 times transation makes 0 profit
    // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
    if (prices.size() <= 1) return 0;
    else {
        int K = 2; // number of max transation allowed
        int maxProf = 0;
        vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
        for (int kk = 1; kk <= K; kk++) {
            int tmpMax = f[kk-1][0] - prices[0];
            for (int ii = 1; ii < prices.size(); ii++) {
                f[kk][ii] = std::max(f[kk][ii-1], prices[ii] + tmpMax);
                tmpMax = std::max(tmpMax, f[kk-1][ii] - prices[ii]);
                maxProf = std::max(f[kk][ii], maxProf);
            }
        }
        return maxProf;
    }
}