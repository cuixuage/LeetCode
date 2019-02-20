/*
只能买卖一次股票的情况下:

给定vector寻找前后差值最大的数值，要求序号高的数字减去序号低的数字。
错误思路: 最长递增子序列 反例:1 5 2 3 4 maxprofit应为4

正确思路:
类似DP动态规划:
保存当前节点为止的最小值,那么profit = array[i] - currentMin;
*/
#include "func.h"
using std::cout;
using std::endl;


//update  一次AC  要想明白逻辑
//数组minVal存储 到当前节点为止的出现的最小股票值 那么profit = prices[i] - minVal[i]
int maxProfit(vector<int>& prices){
    if(prices.size()==0) return 0;
    vector<int> minVal(prices.size(),0);
    minVal[0] = prices[0];
    int profit = 0;
    for(int i=1;i<prices.size();i++){
        if(minVal[i-1] < prices[i])
            minVal[i] = minVal[i-1];
        else
            minVal[i] = prices[i];
        profit = std::max(profit,prices[i]-minVal[i]);
    }
    return profit;   
}
