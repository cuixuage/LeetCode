int removeDuplicates(vector<int>& nums){
    if(nums.size()<=1) return nums.size();
    int p = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            nums[p]=nums[i];
            p++;
        }
    }
    return p;
}
