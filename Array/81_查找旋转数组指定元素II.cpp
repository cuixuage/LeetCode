//一遍AC
//假设可能存在重复元素
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        
        while(left<=right)
        {
            mid = (left + right) >> 1;
            //1. 判断是否为目标
            if(nums[mid] == target) return true;
            //1.1. 特殊处理
            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}
            //2. 左半边有序
            else if(nums[left] <= nums[mid])                //注意这里的小于等于
            {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else
            {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};


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
