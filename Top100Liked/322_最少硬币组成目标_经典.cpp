class Solution {
public:

/*
给target金额,最小的物品个数构成target。每一种硬币无限使用。
背包容量: target
费用重量:array[0]
价值:1      目标:最小化使用数量

completePack 顺序 (而非逆序)
==> dp[i][v] = max{dp[i-1][v],dp[i][v-ci]+wi}
*/

int V =0;
void completepack(vector<int>& F,int costi, int values){
    for(int i=costi;i<=V;i++)
        F[i] = std::min(F[i],F[i-costi]+values);   
}
int coinChange(vector<int>& coins, int target){
    int my_max = target+1;    //巧妙的最大值 & 背包容量设定  target最多由1组成的个数
    V = target;
    vector<int>F(V+1,my_max);          //恰好装满问题; 
    F[0] = 0;
    for(auto& coin : coins){
        completepack(F,coin,1);
    }
    return F.back()==my_max?-1:F.back();
}
};


/*
给定一组硬币,判断硬币最少使用数量 (每一种的硬币,可重复使用硬币) 能否构成terget值
思路1:
target按硬币最大值不断取余(错误)

思路2:  DP
c 硬币的币值
dp存储target,最少需要的的硬币数量
dp[i] = min(dp[i],dp[i-c]+1)
如果i-c>=0 && dp[i-c]!=-1,则表示存在'i-c'的解

解题思路:
硬币种类数组
0,target的递推数组

*/
#include "func.h"

int coinChange(vector<int>& coins,int amount){
    vector<int> dp(amount+1,-1);        //初始化为-1
    dp[0] = 0;
    for(int i=1; i<= amount; ++i)
        for(auto& c : coins)
            if(i-c>=0 && dp[i-c]!=-1)       //dp[i]可以通过前面的某一个dp+c构成
                dp[i]=dp[i]>0 ? std::min(dp[i],dp[i-c]+1) : dp[i-c]+1;
    return dp[amount];
}