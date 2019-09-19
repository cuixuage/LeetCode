#include"func.h"
/*
给定数组，寻找连续的子集使其乘积最大
*/

// dp[i] = dp[i-1]*nums[i] || nums[i]
//用2个dp数组分别记录到i时的最大乘积和最小乘积，因为下一个数字如果为负数就可以把最小的乘积是负的变成正的最大值。

//正确DP 存储当前的min max（因为遇到负数时,max值会"反转"）
int maxProduct(vector<int>& nums){
    int ans = nums[0];
    for(int i=1,imax=ans,imin=ans; i<nums.size();i++){
        //1.
        if(nums[i] < 0) std::swap(imax,imin);
        //2.  此时imax>0,imin<0
        imax = std::max(nums[i], imax*nums[i]);
        imin = std::min(nums[i], imin*nums[i]);
        //3.
        ans = std::max(ans,imax);
    }
    return ans;
}



//ERROR 错误的DP思路
//反例: [-2,3,-4] output=3,except=24
int maxProduct(vector<int>& nums){
    // if(nums.size()==1) return nums[0];
    vector<long> dp(nums.size(),0);
    dp[0] = nums[0];
    long Max = dp[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i] > dp[i-1]*nums[i])
            dp[i] = nums[i];
        else
            dp[i] = dp[i-1]*nums[i];
        Max = std::max(Max,dp[i]);
    }
    return Max;
}