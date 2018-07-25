/*
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
思路:
1.O(N^4)
2.下界 O(N^3)
类似于SumIII  跳过重复元素+排除不符合要求情况
=> 面试题目:抽取4张扑克牌==k 是否存在？
*/
#include "func.h"

vector<vector<int>> fourSum(vector<int>& nums,int target){
    vector<vector<int>> total;
    int len = nums.size();        //避免nums.size()-1做整数比较时候成为大整数
    if (len<4) return total;
    //排序
    sort(nums.begin(),nums.end());
    for(int i=0;i<len-3;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
        for(int j=i+1;j<len-2;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
            if(nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) continue;
            int left=j+1,right=len-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i]+nums[j];
                if (sum<target) left++;
                else if (sum>target) right--;
                else{
                    total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;right--;  //跳过重复元素
                }
            }
        }
    }
    return total;
}

