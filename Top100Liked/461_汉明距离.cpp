/*
汉明距离: 相等长度的字符串 相同位置符号不相同的数量
思路:
1.整数x,y异或 (二进制相同位置的相同数字 变成0)
2.统计二级制中1的个数
*/

//一次AC
#include "func.h"
int hammingDistance(int x, int y){
    int tmp = x^y;
    int count = 0;
    while(tmp!=0){
        tmp = tmp & (tmp-1);
        count++;
    }
    return count;
}

/*
计算二进制中1的个数
思路1:
while(tmp){
    if(tmp & 0x1){
        count++;
        tmp = tmp>>1;
    }
}

思路2:
每次循环都会删除tmp最低位的数字1   时间O(K)
while(tmp){
    tmp = tmp&(tmp-1);
    count++;
}