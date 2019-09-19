//Easy 题目
//sorted array不包含重复元素
int searchInsert(vector<int>& nums, int target){
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

//假如没有重复元素  寻找最后一个小于等于target的位置
//O(logN)
int searchInsert(vector<int>& nums, int target){
    if(nums.size()==0) return 0;
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid] <= target){
            if(mid==nums.size()-1 || nums[mid+1]>target) return mid+1;
            else low = mid+1;
        }
        else  high = mid-1;
    }
    return 0;       //所有的元素都比target大
}