/*
给target金额,最小的物品个数构成target。每一种硬币无限使用。
背包容量: target
费用重量:array[0]
价值:1      目标:最小化使用数量

completePack 顺序 (而非逆序)
==> dp[i][v] = min{dp[i-1][v],dp[i][v-ci]+wi}
*/
#include "func.h"

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

int coinChange(vector<int>& coins, int target){
    int my_max = target+1;
    int V = target;
    int I = coins.size();
    vector<vector<int>> dp(I+1,vector<int>(V+1,my_max));
    dp[0][0] = 0;
    
    for(int i=1;i<=I;i++){
        for(int j=coins[i];j<=V;j++)
            dp[i][j] = std::min(dp[i-1][j],dp[i][j-coins[i]]+1);
    }
    return dp[I][V]==my_max?-1:dp[I-1][V];
}