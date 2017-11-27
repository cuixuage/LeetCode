/*动态规划
S = "rabbbit"，T ="rabbit"
S当中的子字符串 有多少和T字符串相同*/

/*
  S 0123....j
T +----------+
  |1111111111|
0 |0         |
1 |0         |
2 |0         |
. |0         |
. |0         |
i |0         |
如果S中的当前字符不等于当前字符T，那么我们具有与没有新字符时相同数量的不同子序列。
如果S中的当前字符等于当前字符T，那么不同数量的子序列：我们之前所具有的数量加上我们所具有的不同数量的子序列，其中T较少，S较小。
*/
//仍然不是很理解

#include"func.h"
int numDistinct(string S, string T) {
    // 初始化
    int mem[T.length()+1][S.length()+1];         //T中字符作为行
   // bzero(mem,(S.length()-1)*(T.length()-1)*sizeof(int));
    memset(mem,0,(S.length()+1)*(T.length()+1)*sizeof(int));
    for(int j=0; j<=S.length(); j++) {
        mem[0][j] = 1;
    }

    //对于T中每一个字符 去轮询S中所有字符
    for(int i=0; i<T.length(); i++) {
        for(int j=0; j<S.length(); j++) {
            if(T.at(i) == S.at(j)) {
                //？？？？？
                mem[i+1][j+1] = mem[i][j] + mem[i+1][j];
            } else {
                //S中新字符和当前T字符不相同 ;ans相同于尚未加入新字符的值
                mem[i+1][j+1] = mem[i+1][j];
            }
        }
    }

    return mem[T.length()][S.length()];
}


int main(){
    string s="rabbbit";
    string t="rabbit";
    cout<<numDistinct(s,t)<<endl;
    return 0;
}
