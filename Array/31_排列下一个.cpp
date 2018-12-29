/*
给定一个排列,找到当前排列的下一个排列permutation
e.g. 123 -》 132

思路:
1.寻找到最大k,使得nums[k]<nums[k+1].  如果不存在这样的k则reverse nums
2.寻找最大l,使得nums[l]>nums[k] ,交换k,l
3.转置nums[k+1],nums[size-1]
*/

void nextPermutation(vector<int>& nums){
    int n=nums.size();
    int k,l;
    for(k=n-2;k>=0;k--)
        if(nums[k]<nums[k+1]) break;
    //e.g. 321 则k==-1
    if(k<0)
        std::reverse(nums.begin(),nums.end());
    else{
        //note: l>k
        for(l=n-1;l>k;l--)
            if(nums[l]>nums[k]) break;
        std::swap(nums[k],nums[l]);
        std::reverse(nums.begin()+k+1,nums.end());
    }
}
