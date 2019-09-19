/*
堆排序 e.g. 将[1...n]数组升序排列 重写less swap使其满足[0,...,n]排序
核心思路:
1.for循环构造大顶堆
2.不断移出top元素到末尾 + 重新修复堆

构造大顶堆？ sink下沉 序号k元素下沉到恰当位置
1.序号k的两个子元素较大的序号j
2.nums[k] > nums[j]成立, 则k位于恰当位置
否则将父节点k下沉到j位置,继续寻找k恰当位置
*/
#include "func.h"

bool less(vector<int>& nums, int i, int j){
    return nums[i-1] < nums[j-1];
}
void swap(vector<int>& nums,int i,int j){
    std::swap(nums[i-1],nums[j-1]);
}

void sink(vector<int>& nums, int k, int n){
    while(2*k <= n){
        //1.
        int j = 2*k;
        if(j<n && less(nums,j,j+1)) j++;
        //2.
        if(!less(nums,k,j)) break;
        swap(nums,k,j);
        //3.
        k = j;
    }
}
void heapSort(vector<int>& nums){
    int n = nums.size();
    //1. 构建大顶堆
    for(int k=n/2; k>=1; k--)
        sink(nums,k,n);
    //2.
    while(n>1){
        swap(nums,1,n--);
        sink(nums,1,n);     //注意n的值发生改变
    }
}

/*
目标:  升序排列数组

1.构建大顶堆 
for(k=n/2; k>1; k++)
    sink(arr,k,n)
    1.1. sink函数
    while(k*2 <= n)
        寻找子节点的最大值 j
        if 需要将父节点k值做交换
            将节点k和其子节点的最大值做交换(下沉)
        else
            break
2.while(n>1) 将最大值放在数组末尾
    arr[1],arr[n];
    n--;
    sink(arr,i,n)
*/