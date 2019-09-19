/*
正确思路:  
寻找连续的递增序列的若干区间。所有的递增区间都是一次买入卖出的操作，最后将所有利润求和
DP: profitVal[] 以当前元素为止的最大利润

关键点:
dp[i] = dp[i-1]+prices[i]-prices[i-1]    (仍处于递增区间)
      = dp[i-1]     
*/

int maxProfit(vector<int>& prices){
    int n = prices.size();
    if(n==0 || n==1) return 0;
    vector<int> profitVal(n,0);
    int profit = 0;
    for(int i=1;i<n;i++){
        if(prices[i] > prices[i-1])
            profitVal[i] = profitVal[i-1] + prices[i] - prices[i-1];        //核心DP
        else
            profitVal[i] = profitVal[i-1];
        profit = std::max(profit,profitVal[i]);
    }
    return profit;
}


//思路1:  根据121题目 + 贪心  每次找最小最大
//错误e.g.   [7,1,5,3,6,4] output:5  expected:7
public:
    int maxProfit(vector<int>& prices){
        int ans = 0;
        vector<int> oneProfit;
        oneProfit = maxProfit(prices,0,prices.size());
        
        if(oneProfit.empty()) return ans;    
        ans = one_profit[0];
        while(one_profit[1] != prices.size(){
            one_profit = maxProfit(prices,one_profit[1],prices.size());
            ans += one_profit[0];
        }
        return ans;
    }


private:
    vector<int> maxProfit(vector<int>& prices,int start,int end) {
        vector<int> reValue;
        if(start==end) return reValue;
        vector<int> dp(end-start,0);
        int min = prices[start];
        int ans = 0;
        int ansEND = end;
        dp[0]=0;

        for(int i=start;i<end;i++){
            if(prices[i] > prices[i-1])
                dp[i] = prices[i]-min;
            else
                dp[i] = dp[i-1];
            if(min > prices[i])  min = prices[i];
            if(ans < dp[i])  {ans = dp[i]; ansEND = i;}
        }
        reValue.push_back(ans);
        reValue.push_back(ansEND);
        return reValue;
    }
