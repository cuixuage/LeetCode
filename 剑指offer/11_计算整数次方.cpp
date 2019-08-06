/*
给定double base,整数e  计算base的e次方
边界:
1. e 为负数,先转化为正数。 再求最终结果的倒数(注意当base==0时,不能直接求倒数)
2. e=0 return 1


base ^ n =  
1.n为偶数时base^(n/2) * base^(n/2)   
2.n为奇数时base^(n/2) * base^(n/2) * base
*/
#include "func.h"



double Power(double base, unsigned int exponet){
    if(exponet==0) return 1;
    else if(exponet==1) return base;
    //1.
    double result = Power(base, exponet>>1);        //递归
    //2.
    result *= result;
    if(exponet & 0x1 ==1) 
        result *= base;       //expont==奇数
    return result;
}