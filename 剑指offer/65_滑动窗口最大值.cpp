/*
思路: deque 记录当前windows valus降序的index
更新？
1.删除不在window内的index
2.移动window,删除小于新加入val的index
3.push_back(新加入的val) <=> 放在deque最后
4.记录window移动产生的max val
*/
#include "func.h"
vector<int> maxInWindows(vector<int>& array, int K){
    vector<int> ans;
    deque<int> dp;
    if(K==0) return ans;
    for(int i=0;i<array.size();i++){
        //1. window内最大val的删除
        if(!dp.empty() && dp.front() == i-K)    
            dp.pop_front();
        //2. 删除小于新加入val的元素
        while(!dp.empty() && array[dp.back()] < array[i])
            dp.pop_back();
        //3. push_back(新加入的元素)
        dp.push_back(i);
        //4. front计入ans
        if(i >= K-1)
            ans.push_back(array[dp.front()]);
    }
    return ans;
}