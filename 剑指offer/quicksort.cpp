#include "func.h"

//快速排序
//两种方法  注释的方法更少的交换次数
int Partition(int A[],int low,int high){
	int pivot=A[low];
	while(low<high){
		while(low<high&&A[high]>=pivot) --high;
//		A[low]=A[high];
		while(low<high&&A[low]<=pivot)  ++low;
//		A[high]=A[low];
        std::swap(A[high],A[low]);
	}
//	if(A[low] <= pivot) return low;             //如果上面 内部两个while顺序加以交换 那么这里需要判断
//	else return low-1;
    return low;
}
void quicksort(int A[],int low,int high){
	if(low<high){
		int pivotpos=Partition(A,low,high);
        std::swap(A[low],A[pivotpos]);              //确定一个元素的最终位置

		quicksort(A,low,pivotpos-1);
		quicksort(A,pivotpos+1,high);
	}
}

//对于算法的自测
#define SIZE 100
#define TEST_TIMES 1000000

int main()
{
    srand((unsigned)time(NULL));
    int A[SIZE];
    for (int times = 0; times < TEST_TIMES; ++ times)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            A[i] = rand() % SIZE;
        }
        quicksort(A, 0,SIZE-1);
        for (int i = 0; i < SIZE-1; ++i)
        {
            if (A[i] > A[i+1])
            {
                cout << "algorithm failed" << endl;
                for (int j = 0; j < SIZE-1; ++j)
                {
                    cout << A[j] << ",";
                }
                cout << A[SIZE-1] << endl;
                return 1;
            }
        }
    }
    return 0;
}

/*
partion中while语句的交换原因:

如果low在high之前,则low==high的位置满足:
A[low]=A[high]>=A[0]
而A[0]是中枢元素值,紧接着A[low]=A[high]交换到index=0位置
使得不满足 low=high左侧元素小于等于的条件
*/