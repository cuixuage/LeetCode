#include "func.h"
/*
有重复元素的排列问题
e.g. [1,1,2]
第一轮回溯: 将第一个1排在首位的所有排列
第二轮: 将第二个1排在首位; used[]数组判断当前index是否使用过
*/
#include "func.h"

//!used[i-1] 必须加上; i.e.第一轮时, [1,1,2] 重复元素需要tmp add
void backtrack(vector<vector<char>>& ans,vector<char>&tmp,
                string origin,vector<bool>& used){
    if(tmp.size() == origin.size()) 
        ans.push_back(tmp);
    else{
        for(int i=0;i<origin.size();i++){
            if(used[i] || (i>0 && origin[i]==origin[i-1] && !used[i-1]))  //!used[i-1] 必须加上; i.e.第一轮时, [1,1,2] 重复元素需要tmp add
                continue;
            used[i] = true;
            tmp.push_back(origin[i]);
            backtrack(ans,tmp,origin,used);
            used[i] = false;
            tmp.pop_back();
        }
    }
}

vector<string> Permutation(string str) {
    vector<vector<char>> ans;
    vector<char> tmp;
    vector<bool> used(str.size(),false);
    std::sort(str.begin(),str.end());
    backtrack(ans,tmp,str,used);

    vector<string> ans2;
    for(auto& i:ans){
        string tmp = "";
        for(char j:i)
            tmp += j;
        ans2.push_back(tmp);
    }
    return ans2;
}