/*
回文分区
寻找切割点,使得切割后的子串全都是回文字符串
Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
https://leetcode.com/problems/palindrome-partitioning/discuss/182307/Java%3A-Backtracking-Template-General-Approach
回溯模板
*/
#include "func.h"
bool isPalindrome(string s,int low,int high){
    while(low < high){
        if(s[low++] != s[high--]) return false;
    }
    return true;
}
void backtrack(vector<vector<string>>& ans,vector<string>& tmp,
                string& s,int start){
    if(start == s.size())
        ans.push_back(tmp);
    else{
        for(int i=start;i<s.size();i++){
            if(!isPalindrome(s,start,i)) continue;  //只有找到一个回文子串后,才会做backtrack 
            string sub = s.substr(start,i-start+1);
            tmp.push_back(sub);
            backtrack(ans,tmp,s,i+1);   //i+1
            tmp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> tmp;
    backtrack(ans,tmp,s,0);
    return ans;
}