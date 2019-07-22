/*
第index个丑数（由前面的丑数构成）
*/
#include "func.h"

int GetUglyNumber_Solution(int index) {
    if(index <=0 ) return 0;
    if(index == 1) return 1;
    vector<int> dp(index,0);
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    dp[0] = 1;    //init
    for(int i=1;i<index;i++){
        dp[i] = std::min(dp[p1]*2,std::min(dp[p2]*3,dp[p3]*5));
        // point指针的移动
        if(dp[i] == dp[p1]*2) p1++;
        if(dp[i] == dp[p2]*3) p2++; 
        if(dp[i] == dp[p3]*5) p3++;
    }
    return dp[index-1];
}