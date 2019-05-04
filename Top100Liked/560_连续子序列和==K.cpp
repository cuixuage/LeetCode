#include "func.h"
/*  
"连续"子序列的和为定值

1. O(N^3)
暴力搜索所有的子集sum[i,j]
序列[i,j]之和等于K

2.O(N+N^2)
prefix_sum 
序列[i,j]的和等于 prefix[j]-prefix[i]

3.O(N)
hashmap<cur_sum,count>
寻找满足 cur_sum_j - k == cur_sum_i的子集, sum[i,j]==K
*/
// //思路1
// public int subarraySum(int[] nums, int k) {
//         int count = 0;
//         for(int x=0; x < nums.length; x++){
//             for(int y=x; y < nums.length; y++){
//                 int sum = 0;
//                 for(int z=x; z <= y; z++)
//                     sum += nums[z];
//                 if(sum == k)
//                     ++count;
//             }
//         }
//         return count;
//     }

// //思路2
// public int subarraySum(int[] nums, int k) {
//         int count = 0;
//         for(int x=1; x < nums.length; x++)
//             nums[x] += nums[x-1];
//         for(int x=0; x < nums.length; x++){
//             if(nums[x] == k)
//                 ++count;
//             for(int y=x+1; y < nums.length; y++)
//                 if(nums[y]-nums[x] == k)
//                     ++count;
//         }
//         return count;
//     }

//思路3
int subarraySum(vector<int>& nums, int k){
    int count = 0,sum=0;
    unordered_map<int,int> preSum;      //保存到当前为止的元素之和
    preSum[0] = 1;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        //是否存在满足sum[i,j]==k的子集。cur_sum_j - k == map[i] 
        count += preSum.count(sum-k)?preSum[sum-k]:0;       
        preSum[sum] = preSum.count(sum)?preSum[sum]+1:1;
    }
    return count;
}