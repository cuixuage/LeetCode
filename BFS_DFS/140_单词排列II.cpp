/*
给定字符串string
给定wordDict，单词可以使用多次

DFS
*/
#include "func.h"
class Solution{
private:
    unordered_map<string,vector<string>> m;
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();i++)
            prev[i] += " "+word;
        return prev;
    }
public:
    vector<string> wordBreak(string s,  vector<string>& dict){
        if(m.count(s)) return m[s];   //take from memory
        vector<string> result;
        if(std::find(dict.begin(),dict.end(),s) != dict.end() ) 
            result.push_back(s);  //a whole string is a word
        for(int i=1; i<s.size(); ++i){  
            string word = s.substr(i);
            if(std::find(dict.begin(),dict.end(),word) != dict.end() ){
                string rem = s.substr(0,i);
                vector<string> prev = combine(word, wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(),prev.end());
            }
        }
        m[s] = result;  //memorize
        return  result;
    }
};