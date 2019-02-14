/*
快速排序的变型问题
trick：
变量 & 0x1 等于零,变量是偶数
*/
#include "func.h"

void reorderArray(vector<int>& array){
    if(array.size()==0) return;
    int low = 0;
    int high = array.size()-1;
    while(low<high){
        while(low<high && (array[low]&0x1)!=0) ++low;
        while(low<high && (array[high]&0x1)==0) --high;
        if(low<high){
            int tmp = array[low];
            array[low] = array[high];
            array[high] = tmp;
        }
    }
    return;
}