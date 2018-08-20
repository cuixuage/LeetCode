/*
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
#include "func.h"

//currentSum 以当前元素为终止点的  最大sum
int maxSubArray(vector<int>& nums){
    int ans = INT_MIN;
    vector<int> currentSum(nums.size(),INT_MIN);
    //intput [-1] ouput -1
    if(nums.size()==0) return 0;
    for(int i=0;i<nums.size();i++){
        if(i==0) {
            currentSum[i] = nums[i];
            continue;
        }
        if(nums[i] > currentSum[i-1]+nums[i]){
            currentSum[i] = nums[i];
        }else{
            currentSum[i] = currentSum[i-1]+nums[i];
        }
        if(currentSum[i] > ans)
            ans = currentSum[i];
    }
    return ans;
}
