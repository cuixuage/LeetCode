/*
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
candidates中的元素只能被使用一次
同时candidates中的元素不唯一
*/


#include "func.h"
//i>start && origin[i]==origin[i-1]  所有以1开头的组合都被处理，因此应该跳过后面的1
//i> cur意味着cand [i - 1]没有添加到路径中
void backtrack(vector<vector<int>>& ans,vector<int>& tmp,vector<int>& origin,
                int target,int start){
    if(target < 0) return ;
    else if(target == 0) ans.push_back(tmp);
    else{
        for(int i=start;i<origin.size();i++){
            if( i>start && origin[i]==origin[i-1]) continue; //跳过重复的排列 不会重复走同一条路径
            tmp.push_back(origin[i]);
            backtrack(ans,tmp,origin,target-origin[i],i+1); // i+1 同一个元素不能重复使用
            tmp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& nums,int target){
    vector<vector<int>> ans;
    vector<int> tmp;
    std::sort(nums.begin(),nums.end());
    backtrack(ans,tmp,nums,target,0);
    return ans;
}
