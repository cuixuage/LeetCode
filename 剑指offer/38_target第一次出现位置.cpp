/*
target第一次出现的位置
考虑target有可能重复的情况
二分查找
*/  
#include "func.h"
int getFirst(vector<int>& data,int target){
    int low = 0;
    int high = data.size()-1;
    while(low<high){
        int mid = (high-low)/2+low;
        if(data[mid] > target)
            high = mid-1;
        else if(data[mid] < target)
            low = mid+1;
        else{
            //1.  寻找到K值元素 再判断是否为第一个
            if((mid>0 && data[mid-1]!=target) || mid==0) return mid;
            //2. 如果不是第一个,左侧继续二分查找
            else high = mid-1;
        }
    }
    if(data[low]==target) return low;
    return -1;
}