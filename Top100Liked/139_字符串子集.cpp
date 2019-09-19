/*
给定string list,判断某一个单词是否可以被list中的string构成
思路1:
list的全排列,再逐个判断是否满足条件
思路2:
DP 记录string每个位置是否可以被list中的元素组成
dp[i] = true or false
dp[i] = dp[i-1]&&str[i] in list ||
    dp[i-2]&&str[i-1,i] in list ||
    dp[i-3]&&str[i-2,i] in list......
*/

//如果将wordDict转化为hashtable 那么查找速度还可以更快
#include "func.h"
bool wordBreak(string s, vector<string>& wordDict){
    vector<bool> dp(s.size()+1,false);
    dp[0]=true;
    for(int i=1;i<=s.size();i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j]){
            string word  = s.substr(j,i-j);
            if(std::find(wordDict.begin(),wordDict.end(),word) != wordDict.end()){
                dp[i] = true;
                break; //开始判断next i
            }
            }
        }
    }
    return dp[s.size()];
}