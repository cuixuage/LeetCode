/*
无重复元素 存储所有的子集

DFS + back(回溯)
*/
#include "func.h"

//详解 回溯法
/*
假设origin = [0,1,2], tmp = []
i=0 第一轮迭代:
tmp = [0],[0,1],[0,1,2] ==> [0,1] [0]
此时仍有backtrack
[0,2] => [0],[]     (一共4次backtrack)
i++ 第二轮迭代:
tmp [1],[1,2] ==> [1],[] (两次backtrack执行)
.....

每次迭代是以 origin[i]作为起始元素的所有组合
*/


void backtrack(vector<vector<int>>& ans,vector<int>& tmp,vector<int>& origin,int start){
    ans.push_back(tmp);
    for(int i=start; i<origin.size(); i++){
        tmp.push_back(origin[i]);
        backtrack(ans,tmp,origin,i+1);
        tmp.pop_back();
    }
}

vector<vector<int>> subset(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> tmp;
    // std::sort(nums.begin(),nums.end());   //不用排序
    backtrack(ans,tmp,nums,0);
    return ans;
}