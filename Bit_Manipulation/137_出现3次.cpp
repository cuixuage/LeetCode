/*
寻找array中只有一个数字出现1次,其他数字都出现了3次
位运算
O(N)时间复杂度 O(1)空间复杂度
*/
/*思路:
1.这个数字一定是int 分别计算其32位
2.统计所有整数在每一位出现的次数
3.对于3取余,剩下数字即为单独的数字
*/

#include "func.h"

int singleNumber(vector<int>& nums){
    int res = 0;
    //1.
    for(int i=0;i<32;i++){
        int sum = 0;
        //2.
        for(int j=0;j<nums.size();j++){
            sum += (nums[j]>>i) & 0x1;   //&1 只保留最后一位
        }
        //3.
        // res |= (sum%3)<<i;
        res += (sum%3)<<i;
    }
    return res;
}

/*
通用方法 
所有数字出现K次,只有一个数字出现M次
通过真值状态表
https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.
*/
