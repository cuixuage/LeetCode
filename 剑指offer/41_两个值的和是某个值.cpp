/*

核心:  双指针问题

给定数组 寻找其中三个元素使其之和 和target最接近
return 最接近的值
*/
/*
思路:
先排序,再寻找(三个pointer) 时间复杂度是O(N^2)
1.first second thired 如果三个值加起来大于target  thired--
2.三个值加起来小于target second++
3.直到 second 和 thired 相遇 那么first++ 同时重置second和thired
(trick: 重置时候first跳过重复元素)
*/

#include "func.h"

int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    std::sort(nums.begin(),nums.end());
    int closest = nums[0]+nums[1]+nums[2];
    
    for(int first=0;first<nums.size()-2;first++){
        //trick 加速first
        if(first!=0 && nums[first]==nums[first-1]) continue;
        int second = first + 1;
        int thired = nums.size()-1;
        while(second < thired){
            int curSum = nums[first]+nums[second]+nums[thired];
            if(curSum == target) return curSum;
            if(std::abs(target-curSum)<std::abs(target-closest))
                closest = curSum;
            if(curSum > target)
                thired --;
            else
                second ++;
        }
    }
    return closest;
}


/*
三个指针位置:
first,sencond,.......,third
for(first<array.size()){
    //second=fist+1
    //third=arra.size()-1
    while(second < third){
        //首尾指针向中间遍历
    }
}
*/