//一遍AC


int search(vector<int>& nums, int target){
    //empty更快？ 而非使用len 
    if(nums.empty()) return -1;
    
    int start = nums.front();
    int end = nums.back();
    if(target < start && target > end)
        return -1;
    if(target <= end){
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == target)
                return i;
        }
    }else{
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target)
                return i;
        }
    }
    return -1;
}
