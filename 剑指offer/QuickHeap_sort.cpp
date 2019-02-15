/*
快速排序:
不稳定性发生在交换的时刻
e.g. 553355 4 33;选择的中枢元素4,交换数值5,3时刻
注意点:
1. --high是++low的上一条语句(违反顺序是错误的  见quicksort.cpp)
2.while 小于等于的符号 (没有等于可能造成无限循环)
3.注意这两个函数的 input & output
*/

#include "func.h"

int Partition(vector<int>& A, int low, int high){
	int pivot = A[low];                                     //中枢元素
	while(low < high){
		while(low<high && A[high]>=pivot) --high;            //1.
		while(low<high && A[low]<=pivot)  ++low;
        std::swap(A[high], A[low]);
	}
    return low;
}
void quicksort(vector<int>& A, int low, int high){
	if(high <= low) return;
    int pivotpos = Partition(A, low, high);
    std::swap(A[low], A[pivotpos]);              //确定一个元素的最终位置

    quicksort(A, low, pivotpos-1);
    quicksort(A, pivotpos+1, high);
}

/*
3种改进:
1.中枢元素pivot的选择方式
2.小数组使用插入排序  减少递归次数
3.存在大量重复元素时 每次递归将和中枢元素相等的全部元素排列到[lt,gt]之间
得到 nums[lo..lt-1] < v=nums[lt..gt] < nums[gt+1...hi]
*/