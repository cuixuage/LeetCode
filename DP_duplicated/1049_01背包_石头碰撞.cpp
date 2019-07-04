/*
两两的取石头,碰撞后减去小的重量,最后1块石头时的"最小"重量
转化0-1背包:
背包体积: sum(array)/2
重量费用:array[i]
价值:array[i]   本题:设定"价值"=重量

不超过背包容量,计算石头能占据的最大"价值"  
F[0,...V] = 0
*/
#include "func.h"
// 0-1背包遍历物品个数&体积容量

int V = 0;
void zeroOnePack(vector<int>&F,int costi,int valuesi){
    for(int i=V;i>=costi;i--)
        F[i] = std::max(F[i],F[i-costi]+valuesi);
}
int lastStoneWeightII(vector<int>& array){
    int sum = 0;
    for(auto& i : array) sum+=i;
    V = (int)sum/2;
    vector<int> F(V+1,0);     //0.intit 空间长度V+1
    for(int i=0;i<array.size();i++)     //1.遍历每一件物品
        zeroOnePack(F,array[i],array[i]);
    return sum - 2*F.back();
}
