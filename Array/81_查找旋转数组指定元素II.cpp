//一遍AC
//假设可能存在重复元素

bool search(vector<int>& nums, int target) {
    if(nums.empty()) return false;
    
    int start = nums.front();
    int end = nums.back();
    if(target < start && target > end)
        return false;
    if(target <= end){
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == target)
                return true;
        }
    }else{
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target)
                return true;
        }
    }
    return false;    
}
