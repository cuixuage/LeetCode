/*
A[0,1,...,n-1]
B[0,1,.....,n-1]
B[i]=A[0,...,i-1] * A[i+1,...,n-1]
思路:
C[i] = C[i-1]*A[i-1]
D[i] = D[i+1]*A[i+1]    //逆序
*/
#include "func.h"
vector<int> multiply(const vector<int>& A ){
    int length = A.size();
    vector<int> B(length,0);
    vector<int> D(length,0);
    vector<int> C(length,0);
    //正序   相当于自下而上
    C[0] = 1;
    for(int i=1;i<length;i++)
        C[i] = C[i-1]*A[i-1];
    //逆序   相当于自上而下
    D[length-1] = 1;
    for(int i=length-2;i>=0;i--)
        D[i] = D[i+1] * A[i+1];

    for(int i=0;i<length;i++)
        B[i] = C[i]*D[i];
    return B;
}