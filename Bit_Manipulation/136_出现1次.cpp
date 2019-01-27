/*
异或 使得出现两次的数字全部变成 0x0
最终得到数字
*/

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i : nums){
        res ^= i;
    }
    return res;
}
