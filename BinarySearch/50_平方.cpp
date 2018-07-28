#include "func.h"
/*
思路:
次方值为负数 偶数 奇数分别如何处理
*/

double pow(double x,int n){
    if(n==0) return 1;
    if(n<0){
        //e.g.n==-2147483648 换成正数则溢出(INT_MAX 2147483647)
        //此处判断2level 导致1/x > 1， 最后x溢出InTMAX
        n = -n;
        x = 1/x;
    }
    //注意递归 n/2  而非n-1
    return (n%2==0) ? pow(x*x,n/2):x*pow(x*x,n/2);
}

//解决INT_MIN overflow
double pow(double x,int n){
    // cout<<x<< " "<<n<<endl; 
    if(n==0) return 1;
    if(n<0){
        //attention
        if (n==INT_MIN){
            if(x<0) x = -x;
            x = 1/x;
            return x * myPow(x,-(n+1));
        }else{
            n = -n;
        }
        x = 1/x;
    }
    return (n%2==0) ? myPow(x*x,n/2):x*myPow(x*x,n/2);
}