/*
有重复元素的子集问题
DFS + sort skip duplicates
*/
#include "func.h"

// skip duplicates
void backtrack(vector<vector<int>>& ans,vector<int>& tmp,vector<int>& origin,int start){
    ans.push_back(tmp);
    for(int i=start;i<origin.size();i++){
        if(i!=start && origin[i]==origin[i-1]) continue;        //skip duplicates
        tmp.push_back(origin[i]);
        backtrack(ans,tmp,origin,i+1);
        tmp.pop_back();
    }    
}
vector<vector<int>> subsetWithDup(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> tmp;
    std::sort(nums.begin(),nums.end());     //pre-sort
    backtrack(ans,tmp,nums,0);
    return ans;
} 
