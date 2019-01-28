/*
数组中有两个数字出现1次,其他所有数字出现2次
时间O(n)
思路:
将出现1次的数字a,b分到两组,对这两组分别计算一遍
如何分为两组呢？
将a,b两者中最后一位不相同的数字(即倒数第一个为1的位置)来分组
*/

vector<int> singleNumber(vector<int>& nums){
    int aXorb = 0;
    for(int item:nums)
        aXorb ^= item;
    //画图计算理解,最后一个为1的位置
    //lastBit位置为1,其他位置为0
    int lastBit = (aXorb & (aXorb-1))^aXorb;
    int A=0,B=0;
    for(int item:nums){
        if(item & lastBit) A ^= item;
        else B ^= item;
    }
    vector<int> res={A,B};
    return res;
}
//A,B的先后顺序没关系
