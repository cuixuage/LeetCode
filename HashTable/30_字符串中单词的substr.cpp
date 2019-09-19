/*
str: 字符串
words: 等长度单词
寻找str中的substr能够使得words所有的单词出现恰好一次 & 没有其他字符
*/
#include "func.h"
vector<int> findSubstring(string str, vector<string>& words){
    unordered_map<string,int> counts;
    for(string word: words)
        counts[word]++;
    int n = str.size();
    int num = words.size();
    int len = words[0].size();
    vector<int> index;
    if(n<=0 || num<=0) return index;
    for(int i=0;i<n-num*len+1 ;i++){  //substr最短长度num*len
        unordered_map<string,int> seen;
        int j=0;
        while(j<num){
            string word = str.substr(i+j*len,len);
            if(counts.find(word)!=counts.end()){
                seen[word] ++;
                if(seen[word] > (counts.count(word)==0?0:counts[word]))   //单词出现次数过多
                    break;
            }
            else
                break;
            j++;
        }
        if(j==num) index.push_back(i);
    }
    return index;
}