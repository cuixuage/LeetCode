
//N!阶乘的结果包含零的数量  ==>  N本身含有5的因子数目

#include "func.h"
int trailingZeroes(int n) {
    int result = 0;
    for(long long i=5; n/i>0; i*=5){
        result += (n/i);
    }
    return result;
}