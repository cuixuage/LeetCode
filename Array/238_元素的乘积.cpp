#include "func.h"
/*
给定的数组，计算剩余元素的乘积
Input:  [1,2,3,4]
Output: [24,12,8,6]
1. 将所有元素乘积,再除以本身 O(N)
2. 先算最后一个,通过extra变量保存右侧的乘积
*/


vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> res(len,0);
    res[0] = 1;
    for(int i=1;i<len;i++)
        res[i] = res[i-1] * nums[i-1];  //1.从头开始  存储左侧的元素连乘之积
    int right = 1;
    for(int i=len-1; i>=0 ; i--){       //2. 从右往左开始    
        res[i] = res[i]*right;          //左res[i]* 右侧元素的乘积
        right = right*nums[i];             //右侧元素的连续乘积
    }
    return res;
}