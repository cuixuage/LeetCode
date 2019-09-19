
//第K大的数字   （未排序数字+可能存在重复元素）

#include "func.h"
int findKthLargest(vector<int>& nums, int k){
    int index = nums.size()-k;
    int low = 0;
    int high = nums.size()-1;
    int part = -1;
    while(part != index){
        part = partition(nums,low,high);
        if(part==index) return nums[part];
        if(part > index)
            high = part-1;            //二分查找的mid是part 而非(low+high)/2
        else
            low = part+1;   
    }
    return -1;
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