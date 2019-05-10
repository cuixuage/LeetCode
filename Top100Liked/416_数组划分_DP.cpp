#include "func.h"
/*
将数组划分成两部分(顺序可以打乱),使得两部分的和相等
DP
转化为子集和问题  (是否存在一个子集 target=数组总和的一半)
*/
/*
dp[target]一维数组,保存数组内若干元素和是否可以构成target
dp[j] = dp[j] || dp[j-nums[i]]
*/

bool canPartition(vector<int>& nums){
    int sum = std::accumulate(nums.begin(),nums.end(),0);
    int target = sum >> 1;
    if(sum & 1) return false;  //sum奇数
    vector<bool> dp(target+1,false);
    dp[0] = true;
    for( auto& num: nums){
        for( int i = target; i>= num; --i)
            dp[i] = dp[i] || dp[i - num];
    }
    return dp[target];
}

/*
1, 5, 11, 5  return true
dp[j] = dp[j] || dp[j - nums[i]]         (nums[i] <= j <= target)
*/