/*
寻找array中只有一个数字出现1次或者2次,其他数字都出现了3次
位运算
O(N)时间复杂度 O(1)空间复杂度
*/
/*思路:
统计所有位上出现的1次数
对于3取余,剩下数字即为单独的数字
*/
int singleNumber(vector<int>& nums){
    int res = 0;
    //对于32位的整数的每一位bit
    for(int i=0;i<32;i++){
        int sum = 0;
        for(int j=0;j<nums.size();j++){
            //&1 只保留最后一位
            sum += (nums[j]>>i) & 0x1;
        }
        res |= (sum%3)<<i;
    }
    return res;
}

/*
通用方法 
所有数字出现K次,只有一个数字出现M次
通过真值状态表
https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.
*/
