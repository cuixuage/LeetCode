/*
给定vector<string>,string只包含0或者1. 选取最大数量的string,使得0,1总数不超过指定数值
物品: 字符串s1
费用1: s1中'0'的个数
费用2: s1中'1'的个数
容量1: '0'的个数限制V
容量2: '1'的个数限制U
价值: 1     题目要求: 最大化物品的数量

遍历物品个数,容量(逆序)
物品ith有两种费用,不是多重背包问题。多重背包:物品的使用次数不超过Mi次
*/
#include "func.h"

int V = 0;
int U = 0;
void zeroOnePack(vector<vector<int>>& F, int cost1,int cost2,int values){
    for(int i=V;i>=cost1;i--){
        for(int j=U;j>=cost2;j--)
            F[i][j] = std::max(F[i][j],
                                F[i-cost1][j-cost2] + values);      //二维费用更新
    }
}

vector<int> get_0_1_nums(string str){
    vector<int> ans(2,0);
    for(auto& i : str){
        if( i == '0') ans[0] += 1;
        else ans[1] += 1;
    }
    return ans;
}

int findMaxForm(vector<string>& strs,int m,int n){
    V = m;
    U = n;
    vector<vector<int>>F(V+1,vector<int>(U+1,0));  //init; 注意二维费用初始化***
    for(auto& str : strs) {
        vector<int> nums_0_1 = get_0_1_nums(str);
        zeroOnePack(F, nums_0_1[0], nums_0_1[1], 1);
    }
    return F[V][U];    
}