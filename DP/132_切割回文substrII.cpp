/*
将字符串切分为"所有子串都是回文的"的最小切割次数？
DP
https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42213/Easiest-Java-DP-Solution-(97.36)
cut[i] is the minimum of cut[j - 1] + 1 (j <= i), if [j, i] is palindrome.
If [j, i] is palindrome, [j + 1, i - 1] is palindrome, and c[j] == c[i].
*/
#include "func.h"
int minCut(string str){
    int N = str.size();
    vector<int> cut(N,0);
    vector<vector<bool>> dp(N,vector<bool>(N,false));
    for(int i=0; i<N; i++){
        int min_cut = i;
        for(int j=0; j<=i; j++){
            if(str[j]==str[i] && (j+1>i-1 || dp[j+1][i-1])){
                dp[j][i] = true;
                min_cut = (j == 0) ? 0:std::min(min_cut,cut[j-1]+1);
            }
        }
        cut[i] = min_cut;
    }
    return cut[N-1];
}