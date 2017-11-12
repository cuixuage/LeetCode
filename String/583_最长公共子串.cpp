/*
寻找最小的删除步数,使得s1,s2剩余字符相同  =》 寻找最长(可以不连续的)公共子串
=> 动态规划
*/

#include "func.h"
int minDistance(string s1, string s2){
    int l1=s1.length();
    int l2=s2.length();
    int dp[l1+1][l2+1];     //string.length()+1行
    memset(dp,0,sizeof(dp));

    for (int i = 1; i <= l1; i++){
        for (int j = 1; j <= l2; j++){
            //s1[0]s2[0] 存储在 dp[1][1]
            if (s1.at(i-1) == s2.at(j-1))
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //注意dp位置:  字符串的最后一位要考虑进去！其结果存储在dp[s.length]
    return s1.length() + s2.length() - 2 * dp[s1.length()][s2.length()];
}

//***************测试
int main(){
    string s1="sea";
    string s2="eat";
    cout<<minDistance(s1,s2)<<endl;
    return 0;
}
