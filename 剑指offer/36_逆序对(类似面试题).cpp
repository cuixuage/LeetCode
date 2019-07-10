/*
逆序对的统计 转化为归并排序(变型)
NlogN时间
*/
#include "func.h"

vector<int> aux;
int pair_count = 0;
//排序
void merge(vector<int>&array,int low,int mid, int high){
    //排序a[low,mid] 和 a[mid+1,high]两个已排序的片段
    //(p1指向片段1的末尾,P2指向片段2的末尾)
    int p1 = mid;
    int p2 = high;
    for(int k=low;k<=high;k++)
        aux[k] = array[k];
    for(int k=high;k>=low;k--){
        if(p2 < mid+1) array[k] = aux[p1--];
        else if(p1 < low) array[k] = aux[p2--];
        else if(aux[p1] > aux[p2]){
            pair_count += p2 - mid;     //key points(两个已排序的片段之间的逆序对个数)
            array[k] = aux[p1--];
        }
        else array[k] = aux[p2--];
    }
}
//递归
void merge_sort(vector<int>& array,int low, int high){
    if(high <= low) return;
    int mid = low + (high-low)/2;
    //自顶向下
    merge_sort(array,low,mid);
    merge_sort(array,mid+1,high);
    merge(array,low,mid,high);          //执行归并
}

int InversePairs(vector<int>& array) {
    int length = array.size();
    aux.resize(length,0);  //辅助数组
    merge_sort(array,0,length-1);   //call归并排序

    return pair_count;
}