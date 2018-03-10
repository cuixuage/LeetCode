/*
给定vector寻找前后差值最大的数值，要求序号高的数字减去序号低的数字。
错误思路: 最长递增子序列 反例:1 5 2 3 4 maxprofit应为4
*/
#include "func.h"using std::cout;
using std::endl;

//min 记录当前元素前面所有中的最小值
//比较 已经保存的maxprofit 和 value[i]-min的差值区别
int maxProfit(vector<int>& prices) {
    int valMin = INT_MAX;
    int profit = 0;
    for(int i=0;i<prices.size();i++){
        if(prices[i] < valMin) valMin=prices[i];
        profit = std::max(profit,prices[i]-valMin);
    }
    return profit;
}

int main(){
    vector<int> test = {1,2,2,3,3};
    cout<<maxProfit(test)<<endl;
    return 0;
}
