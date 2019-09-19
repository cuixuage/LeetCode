/*
寻找数组中需要调整位置的“substring” 使得数组变得有序
思路1::
O(NlogN) 将数组排序后对照其位置改变首尾位置
思路2:
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103057/Java-O(n)-Time-O(1)-Space
*/

#include "func.h"
int findUnsortedSubarray(vector<int>& nums){
    if(nums.size()==0) return 0;    
    //1.
    vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(),sortedNums.end());
    //2.
    int low = 0;
    int high = nums.size()-1;
    while(low<high && nums[high]==sortedNums[high]) high--;
    while(low<high && nums[low]==sortedNums[low]) low++;
    if(high==low) return 0;
    return high-low+1;
}
//e.g. full-sorted的数组high=0,low=0 return 0;
//测试几个例子