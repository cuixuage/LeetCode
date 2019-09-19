/*
给定未排序的数组 寻找其中最小的未在数组中出现的正整数
O(n)时间 O(1)空间
*/
/*
思路1:
1.我们不关心负数和0
2.不断交换A[i] 和 A[A[i]-1]。 e.g. 数字5和A[4]交换
3.最终是 i+1==A[i]（i由0开始遍历）
不符合条件返回i+1

思路2:
将所有正整数排序  进入1.3判断  我想的  时间不符合
*/

int firstMissingPositive(vector<int>& nums){
    int len = nums.size();
    for(int i=0;i<len;i++){
        //正数 && A[i]-1不越界
        //注意这里的while
        while(nums[i]>0 && nums[i]<=len){           //注意条件:  nums[i]<=len使while并不会死循环
            if(nums[i] != nums[nums[i]-1])
                std::swap(nums[i],nums[nums[i]-1]);
            else
                break;      //找到自己的位置 break  
        }
    }
    
    for(int i=0;i<len;i++)
        if(i+1 != nums[i])
            return i+1;         //从1....n中缺少的最小正整数
    return len;
}
