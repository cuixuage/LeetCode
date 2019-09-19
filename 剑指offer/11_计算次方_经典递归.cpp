/*
给定double base,整数e  计算base的e次方
边界:
1. e 为负数,先转化为正数。 再求最终结果的倒数(注意当base==0时,不能直接求倒数)
2. e=0 return 1
3. base=0,e=负数是无效的
4.计算一个数的乘方的时候，通过计算指数的一半次，得到的结果相乘即可得到，这样计算量会大大减少


base ^ n =  
1.n为偶数时base^(n/2) * base^(n/2)   
2.n为奇数时base^(n/2) * base^(n/2) * base
*/
#include "func.h"



double Power(double base, unsigned int exponet){
    //0. 递归出口
    if(exponet==0) return 1;
    else if(exponet==1) return base;
    //1. 递归 (指数 折半)
    double result = Power(base, exponet>>1);   
    //2. 偶数时平方
    result *= result;

    if(exponet & 0x1 ==1)       //只会执行一次？
        result *= base;       //expont==奇数
    return result;
}