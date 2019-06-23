/*
有重复元素的排列问题
e.g. [1,1,2]
第一轮回溯: 将第一个1排在首位的所有排列
第二轮: 将第二个1排在首位; used[]数组判断当前index是否使用过
*/
#include "func.h"

//!used[i-1] 必须加上; i.e.第一轮时, [1,1,2] 重复元素需要tmp add
void backtrack(vector<vector<int>>& ans,vector<int>&tmp,
                vector<int>&origin,vector<bool>& used){
    if(tmp.size() == origin.size()) 
        ans.push_back(tmp);
    else{
        for(int i=0;i<origin.size();i++){
            if(used[i] || (i>0 && origin[i]==origin[i-1] && !used[i-1]))
                continue;
            used[i] = true;
            tmp.push_back(origin[i]);
            backtrack(ans,tmp,origin,used);
            used[i] = false;
            tmp.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> used(nums.size(),false);
    std::sort(nums.begin(),nums.end());
    backtrack(ans,tmp,nums,used);
    return ans;
}