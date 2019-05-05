#include "func.h"
/*
股票的最大利润: 中间无cooldown冷却间隔
此题允许在购买后、售出后,允许"等待"

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
buy[i] = max(rest[i-1]-price, buy[i-1])
sell[i] = max(buy[i-1]+price, sell[i-1])
rest[i] = max(sell[i-1],buy[i-1],rest[i-1])
note:
buy[i]<=rest[i], rest[i]<=sell[i]  ==> rest[i]=sell[i-1]
==>
buy[i] = max(sell[i-2]-price, buy[i-1])
sell[i] = max(buy[i-1]+price, sell[i-1])
*/

int maxProfit(vector<int>& prices){
    int buy(INT_MIN),sell(0),prev_sell(0),prev_buy(0);
    for (int& price:prices){
        prev_buy = buy;
        buy = std::max(prev_sell - price, buy);
        prev_sell = sell;
        sell = std::max(prev_buy+price, sell);
    }
    return sell;
}