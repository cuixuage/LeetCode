#include "func.h"


//********************* 超时
//*********思路: 获取符合条件的子集 + 寻找sum最大值
//私有变量
int _num_wanted;
int _use_limit;

int is_use_limit(vector<int>& tmp){
    unordered_map<int,int> my_dict;
    for(auto& i : tmp){
        if(my_dict[i]){
            my_dict[i] += 1;
            if(my_dict[i] > _use_limit)
                return false;
        }
        else
            my_dict[i] = 1;
    }
    return true;
}
void backtrack(vector<vector<int>>& ans,vector<int>&tmp,vector<int>&l_tmp,
                vector<int>&origin, vector<int>&label,int start){
    if(tmp.size() > _num_wanted || !is_use_limit(l_tmp))
        return;
    ans.push_back(tmp);
    for(int i=start;i<origin.size();i++){
        tmp.push_back(origin[i]);
        l_tmp.push_back(label[i]);
        backtrack(ans,tmp,l_tmp,origin,label,i+1);
        l_tmp.pop_back();
        tmp.pop_back();
    }
}
int largestValsFromLabels(vector<int>& values, vector<int>& labels, 
                    int num_wanted, int use_limit){
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<int> ltmp;
    _num_wanted = num_wanted;
    _use_limit = use_limit;
    backtrack(ans,tmp,ltmp,values,labels,0);
    int max = 0;
    for(auto& t : ans){
        int cur = 0;
        for(int& i : t)
            cur += i;
        max = std::max(max,cur);
    }
    return max;
}

//***************** 贪心
// 按照values降序 + 限制个数&标签个数
//multi-map (key值重复)

int largestValsFromLabels(vector<int>& values,vector<int>& labels,
                            int num_wanted,int use_limit){
    int res = 0;
    multimap<int,int,std::greater <int>> value_label_map;       //key值降序排列
    unordered_map<int,int> label_count_map;
    for(int i=0;i<values.size();i++)
        value_label_map.insert({values[i], labels[i]});
    for(auto it = value_label_map.begin();it!=value_label_map.end();it++){
        // label使用次数
        if( num_wanted > 0 && ++label_count_map[it->second] <= use_limit){
            res += it->first;
            --num_wanted;
        }
    }
    return res;
}