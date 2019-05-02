#include "func.h"
/*
1. 没有重复元素的数组,第K大数字=快排变型
2. 存在重复的元素呢？
==> 都是kth最大数字
*/

int findKthLargest(vector<int>& nums, int k){
    int index = nums.size()-k;
    int low = 0;
    int high = nums.size()-1;
    int part = -1;
    while(part != index){
        part = partition(nums,low,high);
        if(part >= index)
            high = part;            //二分查找的mid是part 而非(low+high)/2
        else
            low = part+1;   
    }
    return nums[part];
}

int partition(vector<int>&nums,int low, int high){
    int origin_low = low;
    int povit = nums[low];
    while(low < high){
        while(low < high && nums[high]>=povit) high--;
        while(low < high && nums[low]<=povit) low++;
        std::swap(nums[low],nums[high]);
    }
    std::swap(nums[origin_low],nums[low]);
    return low;
}