//删除数组中的重复元素
//辅助pointer  记录非重复的个数
//便利的i速度大于pointer的增长速度
///////////////////////////////////////////////////////////已经排序好的数组(重复元素在一起)
int removeDuplicates(vector<int>& nums){
    if(nums.size()<=1) return nums.size();
    int pointer = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]) 
            continue;
        else{
            nums[pointer] = nums[i];
            pointer++;
        }
    }
    nums.erase(nums.begin()+pointer,nums.end());
    return pointer;
}

//错误思路   只能判断连续的重复元素(题目要求所有出现过的元素都不能重复)
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0 || nums.size()==1) return 0;
    int low = 1;
    int high = nums.size()-1;
    while(low < high){
        while(nums[low]!=nums[low-1] && low<high) low++;
        while(nums[high]==nums[low] && low<high) high--;
        std::swap(nums[low],nums[high])
    }
    nums.erase(nums.begin()+low,nums.end());
    return low;
}
