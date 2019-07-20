/*
1~n的数组中,整数1出现的次数
思路1:  每一个数字计算一次包含1的个数
思路2:  递归,每次只计算最高位带来的1的个数
*/
#include "func.h"
int powerbase10(int n){
    int result = 1;
    for(unsigned int i = 0;i<n;i++)
        result *=  10;
    return result;
}
int Numberof1(const char* strN){
    if(!strN || *strN < '0' || *strN > '9' || *strN=='\0')
        return 0;
    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));
    if(length==1 && first==0) return 0;
    if(length==1 && first>0) return 1;

    //最高位1的个数
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = powerbase10(length-1);
    else if(first == 1)
        numFirstDigit = std::atoi(strN+1)+1;
    //除了第一位以外的1的个数
    int numOtherDigits = first * (length-1) * powerbase10(length-2);
    //递归
    int numRecursive = Numberof1(strN + 1); //删除最高位

    return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN_Solution(int n){
    if(n <= 0) return 0;
    char strN[50];
    sprintf(strN,"%d",n);
    return Numberof1(strN);
}