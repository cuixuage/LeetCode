/*
完全背包问题 & 记录方案总数 & 恰好装满问题
将转移方程中的max => sum
F[0] = 1, F[1,...v]=0  ？

F[i][v] = sum{F[i-1][v],F[i][v-ci]} 
*/
#include "func.h"

int V =0;
void completepack(vector<int>& F,int costi){
    for(int i=costi;i<=V;i++)
        F[i] = F[i] + F[i-costi];       //sum  方案总数问题
}
int change(int target, vector<int>& coins){
    int my_max = target+1;    //巧妙的最大值 & 背包容量设定  target最多由1组成的个数
    V = target;
    vector<int>F(V+1,0);          //恰好装满问题; 
    F[0] = 1;
    for(auto& coin : coins){
        completepack(F,coin);
    }
    return F.back();
}