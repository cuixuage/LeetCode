/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2,-1);
    if(nums.size()==0)    return res; 
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target && res[0]==-1)
            res[0] = i;
        //这里判断条件注意思考
        // //[3,3,3] expected output=[0,2]
        // else if(nums[i]==target && res[1]==-1)
         else if(nums[i]==target && res[0]!=-1)
            res[1] = i;
        if(nums[i] > target)
            break;
    }
    if(res[0]!=-1 && res[1]==-1)
        res[1] = res[0];
    return res; 
}
