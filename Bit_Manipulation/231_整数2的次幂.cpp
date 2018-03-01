//判断给定的整数是否为2的次幂
//思路: 给定整数转换为2进制后的1的个数为0或者1个。 那么将整数不断&1 可以得到尾数是否为1

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

bool isPowerOfTwo(int n){
    if( n < 0) return false;
    bool hasone = false;
    while (n > 0){
        if (n & 1){         //数字二进制最后1位为1
            if (hasone) return false; //已经存在1位
            else hasone = true;
        }
        n >>=1;  //数字n右移1位
    }
    return hasone;
    //return true;   //error 因为当n==0时需要返回false
}

int main(){
    cout<< isPowerOfTwo(100) <<endl;
    return 0;
}
