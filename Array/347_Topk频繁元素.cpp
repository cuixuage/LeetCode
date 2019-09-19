#include "func.h"
/*
给定元素数组寻找其中出现次数最高的K个元素
note: 时间复杂度要优于O(NlogN)
*/

vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int,int> map;
    for(int num : nums){
        map[num] ++;
    }
    vector<int> res;
    //pair first is fequency, second is number
    priority_queue<pair<int,int>> pq;                   //大顶堆
    for(auto it=map.begin(); it!=map.end();it++){
        pq.push(make_pair(it->second,it->first));
        if(pq.size() > (int)map.size() -k){             //当堆中元素大于 size-K时,取出数字
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}