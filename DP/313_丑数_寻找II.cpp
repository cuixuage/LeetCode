/*
丑数构成的因子改为list
计算第K个丑数

关键: 丑数 = 因子指针 * dp[i]
F(m) = min(F(i)*2,min(F(j)*3,F(k)5)) 

dp{i} 第ith的丑数; 因子指针的移动
*/
#include "func.h"
int nthSuperUglyNumber(int Kth, vector<int>& primes) {
    vector<int> dp(Kth,INT32_MAX);
    dp[0] = 1; //init
    vector<int> pointers(primes.size(),0);  //按照primes index序号记录因子的使用次数

    for(int i=1;i<Kth;i++){
        int tmp = INT32_MAX;
        //寻找ith丑数
        for(int j=0;j<primes.size();j++)
            dp[i] = std::min(dp[i],
                    dp[pointers[j]] * primes[j] );//dp[因子使用次数] * 因子
        //对应的因子 ++
        for(int j=0;j<pointers.size();j++)
            if(dp[i] == dp[pointers[j]] * primes[j])
                pointers[j] ++;
    }
    return dp[Kth-1];
}