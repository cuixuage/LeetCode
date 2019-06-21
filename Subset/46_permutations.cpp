#include "func.h"
/*
无重复元素数组  "所有排列"
区别: 子集是不考虑元素之间的顺序性的

注意: 排列   排列后的长度=原始数组长度
*/

//回溯 参数只有三个 没有"start"
// i每次都从"零"开始  + 如果元素已经遍历则continue
void backtrack(vector<vector<int>>& ans, vector<int>& tmp, vector<int>&origin){
    if(tmp.size()==origin.size())
        ans.push_back(tmp);
    else{
        for(int i=0;i<origin.size();i++){
            if(std::find(tmp.begin(),tmp.end(),origin[i]) != tmp.end()) continue;
            tmp.push_back(origin[i]);
            backtrack(ans,tmp,origin);
            tmp.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> tmp;
    // not sort
    backtrack(ans,tmp,nums);
    return ans;
}