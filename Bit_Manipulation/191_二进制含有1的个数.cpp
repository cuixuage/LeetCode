
//把n与1做二进制的与(AND)运算，即可判断它的最低位是否为1。如果是的话，把计数变量加一。
//然后把n向右移动一位，重复上述操作
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(){
    cout<<hammingWeight(2)<<endl;
}
