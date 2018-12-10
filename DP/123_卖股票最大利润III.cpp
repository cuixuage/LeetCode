//在122题目的基础上  增加限制交易次数为两次

//错误思路:
//思路:   寻找所有的递增区间  找出其中差值最大的两次5
//e.g. {1,2,4,2,5,7,2,4,9,0} expected: 1~7 + 2~9 == 13  output:12
// int maxProfit(vector<int>& prices){
//     int n = prices.size();
//     if(n==0||n==1) return 0;
//     vector<int> dp(n,0);
//     vector<int> ans(n,0);
//     int tmp=0;
//     //每次dp[i]=0 都是新的买入点
//     for(int i=1;i<n;i++){
//         if(prices[i] > prices[i-1]) 
//             dp[i] = dp[i-1]+ prices[i] - prices[i-1];
//         if(dp[i]==0){
//             ans.push_back(tmp);
//             tmp = 0;
//         }else{
//             tmp += dp[i]-dp[i-1];
//         }
//     }
//     ans.push_back(tmp);
//     std::sort(ans.begin(),ans.end());
//     return ans[-1]+ans[-2];
// }


//正确思路:   再进行理解~~~~   现在不是很明白
//递推公式:  dp[k,i] = max(dp[k,i-1],  prices[i]-prices[j]+dp[k-1,j-1])
//k是第k次交易 第i天
//如果不交易 等于前一天的利润
//第i天卖出 那么利润是prices[i]-prices[i-1]+dp[i-1,j-1] 上回合交易的+前一天

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
