/*
无重复元素 + 组合
从数组中挑选(可重复选取同一个元素)得到目标target的元素组合
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
*/
#include "func.h"
//target = target - origin[i] 
//start = i 而非i+1。  因为同一个元素可以重复使用!
void backtrack(vector<vector<int>>& ans,vector<int>&tmp,
                vector<int>&origin,int target,int start){
    if(target < 0) return;
    else if(target==0) ans.push_back(tmp);          //target 元素组合
    else{
        for(int i=start;i<origin.size();i++){
            tmp.push_back(origin[i]);
            backtrack(ans,tmp,origin,target-origin[i],i);   //not i+1 （同一个元素重复使用）
            tmp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& nums,int target){
    vector<vector<int>> ans;
    vector<int> tmp;
    // std::sort(nums.begin(),nums.end());   //排序是不必要的
    backtrack(ans,tmp,nums,target,0);
    return ans;
}