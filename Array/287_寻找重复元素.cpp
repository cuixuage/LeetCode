#include "func.h"
/*
数组中包含1~n的数字,共有n+1个元素. 找到唯一一个重复的元素.
注意: 重复元素可能出现多次
1.有一个元素数组内出现1半次数以上  （排序nlogN; 次数来统计)
2.位运算  解决只出两次的重读元素？？？
3.二分查找
*/

int findDulicate(vector<int>& nums){
    int n = nums.size()-1;
    int low = 1;
    int high = n;
    int mid;
    while(low < high){
        mid = (low+high)/2;
        int count = 0;
        for(int num : nums)
            if(num <= mid) count++;
        if(count > mid) high = mid;
        else low = mid + 1;
    }
    return low;
    // return high;
}