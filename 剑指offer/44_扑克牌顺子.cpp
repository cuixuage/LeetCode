/*
判断扑克牌是否存在顺子
1.排序
2.统计数字0(大、小王)
3.统计数字两两之间的间隔
4.排除重复元素的情况
*/
#include "func.h"
bool IsContinuous(vector<int>& array){
    if(array.size()==0) return false;
    std::sort(array.begin(),array.end());
    int number_0 = 0;
    for(auto& i : array)
        if(i==0) number_0 += 1;
    int internel = 0;
    for(int i=1;i<array.size();i++){
        if(array[i-1]==0) continue;                 //note
        if(array[i-1] == array[i]) return false;
        internel += (array[i]-array[i-1])-1;
    }
    return number_0 >= internel?1:0;
}