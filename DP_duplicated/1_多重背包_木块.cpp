/*
一共N个木块, 第一个位置放1个木块,后面的位置不低于前一个位置的木块。一共有多少种安放方案？
思路1:
转化为多重背包问题
背包容量: N
花费(每个位置的木块使用数量):1,2,3....N
使用次数限制:N,N/2,N/3,......1
价值:0          (求方案总数 sum)

F[i,V] = sum(F[i-1,V-k*costi])   0=<k<=Mi  (此题限制次数: Mi=N/costi)
*/
#include "func.h"
int V = 0;
int multiPackage(int N){
    V = N;
    vector<int> cost(N+1,0);
    for(int i=1;i<=N;i++)   cost[i] = i;
    vector<vector<int>> dp(N+1,vector<int>(V+1,0));     //物品个数N,背包容量N
    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<=N/cost[i];k++)
                if(k*cost[i] <= j)
                    dp[i][j] += dp[i-1][j-k*cost[i]];       //F[i,V] = sum(F[i-1,V-k*costi])多重背包
        }
    }
    return dp[N][N];
}

int main(){
    for(int i=1;i<=7;i++)
        cout<<multiPackage(i)<<endl;
    return 0;
}

/*
拓展:
切割钢条问题,每段钢条有不一样的value
思路1:
多重背包(背包恰好装满,value,使用次数)
思路2:
dp[i] = max(dp[i-1]+dp[1],dp[i-2]+dp[2],dp[i-3]+dp[3]......)  挑选最大值

整数划分问题:
一个整数可以被多少种整数组成,(1,2,3,....,n) => 多重背包问题,sum方案次数问题