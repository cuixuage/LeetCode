/*
0-1背包的恰好装满的问题
选择若干物品,使得物品价值和  恰好等于sum(array)/2
背包容量: sum(array)/2
重量花费cost: array[i]
物品价值: 0         本题: 恰好装满问题,无最大化目标

恰好装满: dp[0]=0, dp[1,...V]=INT_MIN
*/
#include "func.h"

int V = 0; //背包体积
void zeroOnePack(vector<int>&F,int costi, int weighti){
    for(int i=V;i>=costi;i--)           //3. >=,逆序
        F[i] = std::max(F[i],F[i-costi]+weighti);
}
bool canPartition(vector<int>& array){
    int sum = 0;
    for(auto& i : array) sum += i;
    if(sum%2) return false;
    V = sum/2;
    vector<int> F(V+1,INT32_MIN);       //0.init V+1空间长度
    F[0] = 0;
    for(int i=0;i<array.size();i++)     //遍历每一件物品
        zeroOnePack(F,array[i],0);      //1.zeroOnePack
    if(F.back() == INT32_MIN)  return false;
    else return true;
}