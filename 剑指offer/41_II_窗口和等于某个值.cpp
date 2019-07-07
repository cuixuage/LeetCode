/*
41. 当只有两个、三个非连续的数值等于target
变型: “连续”的窗口内的和等于target,  array从

手段: 记录窗口的[begin,end] sum<target,end++; sum>target,begin++;
*/
#include "func.h"

vector<int> getOneSeq(int first,int last){
    vector<int> ans;
    for(int i=first;i<=last;i++)
        ans.push_back(i);
    return ans;

}
vector<vector<int>> FindContinuousSequence(int target){
    vector<vector<int>> ans;
    if(target < 3) return ans;
    int first = 1;
    int last = 2;
    int begin_upbound = target/2;
    int sum = first + last;
    while(first <= begin_upbound && last<=target){
        if(sum==target)
            ans.push_back(getOneSeq(first,last));
        while(sum>target && first<=begin_upbound){      //关键  减少时间损耗
            sum -= first;
            first += 1;
            if(sum==target)
                ans.push_back(getOneSeq(first,last));
        }
        last += 1;
        sum += last;
    }
    return ans;
}