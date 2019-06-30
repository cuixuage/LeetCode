

#include "func.h"
//连续子集问题
// dp[i] = max(array[i] , dp[i-1]+array[i]) (当array[i]>=0时)
int maxSubArray(vector<int>& nums){
    if(nums.size()==0) return 0;
    vector<int> dp(nums.size(),0);
    int max = std::max(0,nums[0]);
    dp[0] = nums[0];            //dp init

    for(int i=1;i<nums.size();i++){
        dp[i] = std::max(nums[i],dp[i-1]+nums[i]);
        max = std::max(dp[i],max);
    }
    return max;
}



// 非连续子集问题
// dp[i] = max(dp[i-1] , dp[i-1]+array[i]) (当array[i]>=0时)
int maxSubArray(vector<int>& nums){
    int len = nums.size();
    vector<int> dp(nums.size(),0);
    int max = std::max(0,nums[0]);
    dp[0] = nums[0];            //dp init
    for(int i=1;i<len;i++){
        dp[i] = std::max(dp[i-1],dp[i-1]+nums[i]);
        max = std::max(dp[i],max);
    }
    return max;
}