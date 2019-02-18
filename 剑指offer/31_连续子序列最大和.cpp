/*
DP动态规划
以i结尾的子序列的最大和  最终求max
*/

int findMaxSum(vector<int>& nums){
    if(nums.size()==0) return 0;
    //1. init
    int maxVal = 0;
    vector<int> seqence(nums.size(),0);
    if(nums[0] >= 0){
        seqence[0] = nums[0];
        maxVal = nums[0];
    } 
    //2. DP
    for(int i=1;i<nums.size();i++){
        if(seqence[i-1] <= 0)
            seqence[i] = nums[i];
        else    
            seqence[i] = nums[i] + seqence[i-1];
        maxVal = std::max(seqence[i],maxVal);
    }
    return maxVal;
}

//假设子序列的长度至少为1
int findMaxSum(vector<int>& nums){
    if(nums.size()==0) return 0;
    //1. init
    int maxVal = 0;
    vector<int> seqence(nums.size(),0);
    seqence[0] = nums[0];
    maxVal = nums[0];
    
    //2. DP
    for(int i=1;i<nums.size();i++){
        if(seqence[i-1] <= 0)
            seqence[i] = nums[i];
        else    
            seqence[i] = nums[i] + seqence[i-1];
        maxVal = std::max(seqence[i],maxVal);
    }
    return maxVal;
}