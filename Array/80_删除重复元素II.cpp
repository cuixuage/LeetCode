//区别于26题 
//升序的输入 最多出现两次重复元素

int removeDuplicates(vector<int>& nums){
    int n=nums.size();
    int count = 0;      //用来记录待删除的元素数目
    //nums i-2-count的位置连续三元素的第一个元素
    for(int i=2;i<n;i++){
        //输入的是有序数组 等价nums[i]==nums[i] && nums[i]==nums[i-2-count]
        if(nums[i]==nums[i-2-count]) count++;
        else nums[i-count] = nums[i];
    }
    return n-count;
}


//Error 错误思路
/*
Your input
[1,1,1,2,2,3]
Output
[1,1,2,3]           //由于pi位置被修改
Diff
Expected
[1,1,2,2,3]
*/
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <=2) return nums.size();
    int pi = 2;
    for(int i=2;i<nums.size();i++){
        if(nums[i]==nums[i-1]==nums[i-2])
            continue;
        else{
            nums[pi] = nums[i];
            pi++;
        }
    }
    nums.erase(nums.begin()+pi,nums.end());
    return nums.size();
}
