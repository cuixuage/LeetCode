//Easy 题目
//sorted array不包含重复元素
int searchInsert(vector<int>& nums, int target) {
    if(nums.size()==0) return 0;
    else if(nums.size()==1 && target<=nums[0]) return 0;
    else if(nums.size()==1 && target>nums[0]) return 1;
    else{
        //e.g. target=0 and nums=[1,3,5,6] output=0
        if(target <= nums[0]) return 0;
        for(int i=1;i<nums.size();i++){
            if(target>nums[i-1] && target<=nums[i])
                return i;
        }   
    }
    return nums.size();
}
