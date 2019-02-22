/*
珠宝和石头 jewels and stones
1.auto 遍历
2.std::count 函数
*/
#include "func.h"

//一次AC
int numJewelsInStones(string J, string S) {
    int count = 0;
    for(char j:J){
        count += std::count(S.begin(),S.end(),j);
    }
    return count;
}