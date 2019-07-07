/*
C语言的字符串翻转
*/
#include "func.h"
void Reverse(char* pBegin, char* pEnd){
    if(pBegin==NULL || pEnd==NULL)
        return;
    while(pBegin < pEnd){       //首尾交换
        std::swap(*pBegin,*pEnd);
    }
    pBegin ++;
    pEnd --;
}
