//quicksort的变型
#include "func.h"
void reorderArray(int *pdata,unsigned int length){
    if(pdata==NULL || length==0) return;
    int *pbegin = pdata;
    int *pend = pdata+length-1;
    while(pbegin<pend){                 //比较地址的大小
        while(pbegin<pend && (*pbegin & 1)!=0)   ++pbegin;
        while(pbegin<pend && (*pend & 1)==0) --pend;
        if(pbegin<pend) std::swap(*pbegin,*pend);
    }
}

int main(int argc,char** argv){
    int *A = new int[10];
    for(int i=0;i<10;i++)
        A[i]=i+1;
//    //测试栈的生长方向,可能数组就是这种情况吧。
//    //一般来说 栈是向地址减少方向增长
//    for(int k=0;k<10;k++){
//        printf("%x %d\n",A,*A);
//        A++;
//    }
    reorderArray(A,10);
    for(int k=0;k<10;k++){
        printf("%x %d\n",A,*A);
        A++;
    }
    return 0;
}
