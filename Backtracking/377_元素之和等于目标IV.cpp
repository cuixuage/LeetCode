/*
Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
*/
//类似于39题  beign每次从零开始即可(  Error:Memory Limit)
//output=7  元素可以重复使用 & 区分combination的内部顺序

//ERROR 递归超时 time limit exceeded
public int combinationSum4(vector<int>& nums, int target) {
    if (target == 0) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (target >= nums[i]) {
            res += combinationSum4(nums, target - nums[i]);
        }
    }
    return res;
}

//for循环  DP找出存储中间结果的方法，以避免多次计算相同的组合和
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    sort (nums.begin(), nums.end());
    //dp[i] : record the possible combination count to sum to target value of i
    for (int i = 1; i <= target; i++) {
        for (auto num : nums) {    
            //没想明白
            if (i < num) break;
            dp[i] += dp[i - num];
        }
    }
    return dp.back();
}

//java 自上而下

private int[] dp;

public int combinationSum4(int[] nums, int target) {
    dp = new int[target + 1];
    Arrays.fill(dp, -1);
    dp[0] = 1;
    return helper(nums, target);
}

private int helper(int[] nums, int target) {
    if (dp[target] != -1) {
        return dp[target];
    }
    int res = 0;
    for (int i = 0; i < nums.length; i++) {
        if (target >= nums[i]) {
            res += helper(nums, target - nums[i]);
        }
    }
    dp[target] = res;
    return res;
}
