/*
使用位运算 求和两个整数数字
*/
#include "func.h"
int Add(int num1,int num2){
    int sum = 0;
    int carry = 0; //进位
    do{
        sum = num1 ^ num2;  //异或(数字,相加不进位)
        carry = (num1 & num2)<<1;   //与&左移1位 (记录进位)

        num1 = sum;
        num2 = carry;
    }while(num2 != 0);    //e.g. num1=3,num2=0时
    return sum;
}