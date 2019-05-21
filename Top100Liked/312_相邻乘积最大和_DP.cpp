#include "func.h"
/*
寻找coins[i]=coins[left]*coins[i]*coins[right]
sum(coins[i])最大的 获取方式
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

自顶向下思路 假如我们只有最后一个气球 == nums[-1]*nums[i]*nums[n]
dp[left][right]代表left,right之间能获得的最大硬币
for（int k = left; k <= right; ++ k）
dp [left] [right] = max（dp [left] [right]，nums [left-1] * nums [k] * nums [right + 1] + dp [left] [k-1] + dp [k + 1] [right]）
*/

//仔细理解下吧
int maxCoinsDP(vector<int>& iNums){
    int nums[iNums.size() + 2];
    int n =1;
    //跳过元素0的位置
    for(int x:iNums) if(x>0) nums[n++] = x;
    nums[0] = nums[n++] = 1;

    int dp[n][n] = {};
    for(int k=2;k<n;++k){
        for(int left=0;left<n-k;++left){
            int right = left + k;
            for(int i=left+1; i<right; ++i)
                dp[left][right] = std::max(dp[left][right],
                    nums[left]*nums[i]*nums[right] + dp[left][i] +dp[i][right]);

        }
    }
    return dp[0][n-1];
}

// https://leetcode.com/problems/burst-balloons/discuss/76229/For-anyone-that-is-still-confused-after-reading-all-kinds-of-explanations