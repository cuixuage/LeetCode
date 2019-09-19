/*
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
//数组中没有重复元素  &   每个元素可以重复使用
//类似于DFS的思想    回溯
//对比题目77题

#include"func.h"
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(),candidates.end());             //不排序 无法通过case
    vector<vector<int>> ans;
    vector<int> tmp;
    combinationSum(candidates,target,ans,tmp,0);
    return ans;
}

void combinationSum(vector<int>& arr,int target,vector<vector<int>>& ans,vector<int>& tmp,int begin){
    //target==0 means成功寻找到
    if(!target){
        ans.push_back(tmp);
        return;
    }
    //注意回溯时begin位置  仍然是i
    for(int i=begin;i!=arr.size() && target >= arr[i]; ++i){
        tmp.push_back(arr[i]);
        combinationSum(arr,target-arr[i],ans,tmp,i);     //因为同一个元素可以重复使用
        tmp.pop_back();
    }
}
