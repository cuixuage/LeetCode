/*
不使用乘法 除法 mod直接进行计算  如何得到两个数的商？

思路1:
循环减法  
思路2:
移位减  util dvd >= (dvs<<1)，此时被除数是除数的一点几倍
res+1
*/


int divide(int dividend, int divisor){
    if(0==divisor || (dividend==INT_MIN&&divisor==-1))
        return INT_MAX;
    //异或
    int flag =((dividend>0) ^ (divisor>0))==true?-1:1; 
    //注意溢出的问题  [-2^31 ~ 2^31-1]
    long long ldvd = std::labs(dividend);
    long long ldvs = std::labs(divisor);
    int  res = 0;
    
    while(ldvd >= ldvs){
        long long tmp = ldvs,count=1;
        //count倍数 1,2,4,8....
        //(商为奇数时)最后一次外循环 不会进入到下面的内循环
        while(ldvd >= (tmp<<1)){
            tmp = tmp<<1;
            count = count<<1;
        }
        ldvd -= tmp;
        res += count;
    }
    return flag==1?res:-res;
}
