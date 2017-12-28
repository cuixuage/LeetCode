#include "func.h"

//��������
//���ַ���  ע�͵ķ������ٵĽ�������
int Partition(int A[],int low,int high){
	int pivot=A[low];
	while(low<high){
		while(low<high&&A[high]>=pivot) --high;
//		A[low]=A[high];
		while(low<high&&A[low]<=pivot)  ++low;
//		A[high]=A[low];
        std::swap(A[high],A[low]);
	}
//	if(A[low] <= pivot) return low;             //������� �ڲ�����while˳����Խ��� ��ô������Ҫ�ж�
//	else return low-1;
    return low;
}
void quicksort(int A[],int low,int high){
	if(low<high){
		int pivotpos=Partition(A,low,high);
        std::swap(A[low],A[pivotpos]);              //ȷ��һ��Ԫ�ص�����λ��

		quicksort(A,low,pivotpos-1);
		quicksort(A,pivotpos+1,high);
	}
}

//�����㷨���Բ�
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
