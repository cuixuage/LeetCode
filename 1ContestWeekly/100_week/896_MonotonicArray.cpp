#include "func.h"
/*
判断数组的单调性
*/

//Accept
bool isMonotonic(vector<int>& A){
    if(A.size()<=2) return true;         //2个元素肯定是单调的
    int flag1 = 0;
    int flag2 = 0;
    //递增
    for(int i=1;i<A.size();i++){
        if(A[i]>=A[i-1]) continue;
        else flag1 =-1;
    }
    //递减
    for(int i=1;i<A.size();i++){
        if(A[i]<=A[i-1]) continue;
        else flag2 =-1;
    }
    if(flag1==0 || flag2==0) return true;
    else return false;
}

//错误方法  因为存在重复元素
//例如:  5 6 8 8 7
//无法判断
bool isMonotonic2(vector<int>& A){
    if(A.size()<=2) return true;
    for(int i=0;i<A.size()-1;i++){
        if((A[i+1]-A[i])*(A[i+2]-A[i+1]) < 0) return false;
    }

}
