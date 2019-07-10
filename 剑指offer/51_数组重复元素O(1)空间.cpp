/*
数组的元素取值范围在[0,N-1]之间。 数组长度是N
思路1:
hash,如果数字已经存在则说明是重复元素 O(N)时间  O(N)空间
思路2:
O(1)空间
key points: array[i]=M,其排序后的位置处于index=M
for( all element index){
    while(array[index] != index)        //寻找排序后的位置
        swap
}
*/
#include "func.h"
bool duplicate(int array[], int length, int* duplication){
    if(array==NULL || length<=0) return false;
    for(int i=0;i<length;i++){
        while(array[i] != i){
            int index = array[i];   //排序后 array[i]应该处于的位置
            if(array[i] == array[index]){
                *duplication = array[i];
                return true;
            }
            std::swap(array[i],array[index]);
        }
    }
    return false;
}