//给定两个单词（beginWord和endWord）和一个字典的单词列表，找到从beginWord到endWord的最短转换序列的长度
//begin end没有重复字符,都不为空，长度大小相同

#include "func.h"

//仔细理解BFS的思想
//每一层相对于上一层都只相差一个字符
//每一层的queue是如何根据unorderset构造出来的？？
//**********超时   把vector换成unordered_set应该可以快不少
int ladderLength(string beginword, string endword, vector<string>& worddict){
    //worddict.push_back(endword);
    queue<string> tovisit;
    addNextWords(beginword,worddict,tovisit);               //初始化tovisit 只保存和beginword相差一个字符的单词
    int dist = 2;
    while(!tovisit.empty()){
        int num = tovisit.size();
        for(int i=0;i<num;i++){
            string word = tovisit.front();
            tovisit.pop();
            if(word == endword) return dist;
            addNextWords(word,worddict,tovisit);
        }
        dist++;
    }
    return 0;       //没有找到结果
}

//word == tovisit.front()
//在worddict中寻找相对于word又改变了一个字符的单词
void addNextWords(string word,vector<string>& wordDict,queue<string>& toVisit){
    wordDict.erase(std::remove(wordDict.begin(), wordDict.end(), word), wordDict.end());		//实参传递 erase相当于标记已遍历
    for(int p=0;p<(int)word.length();p++){
        char letter = word[p];
        for(int k=0;k<26;k++){
            word[p] = 'a' + k;
            if(std::find(wordDict.begin(),wordDict.end(),word) != wordDict.end()){
                toVisit.push(word);
                wordDict.erase(std::remove(wordDict.begin(), wordDict.end(), word), wordDict.end());            //删除被使用过的word  相当于标记已遍历
            }
        }
        word[p] = letter;
    }
}

int main(int argc,char**argv){
    string beginword = "hit";
    string endword = "cog";
    vector<string> wordDict = {"hot", "dot", "dog", "lot", "log","cog"};
    cout<< ladderLength(beginword,endword,wordDict) <<endl;
    return 0;

}

//leetcode 127 https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C++-Solution-using-BFS
//由于每次只能更改一个字母，如果我们从一开始"hit"，我们只能更改为那些只有一个字母的单词，例如"hot"。以图论的方式来说，我们可以说这"hot"是一个邻居"hit"。
//这个想法很简单，先来看看start它的邻居，然后拜访其邻居的未访问邻居......嗯，这只是典型的BFS结构。
//
//为了简化问题，我们插入end到dict。
//我们dist为变换的当前距离保留一个变量，并dist++在完成一轮BFS搜索（请注意，它应该符合问题描述中距离的定义）后进行更新。
//此外，为避免多次访问某个单词，我们会在访问该单词dict后将其删除

//
//
//public:
// int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
//        wordDict.insert(endWord);
//        queue<string> toVisit;
//        addNextWords(beginWord, wordDict, toVisit);
//        int dist = 2;
//        while (!toVisit.empty()) {
//            int num = toVisit.size();
//            for (int i = 0; i < num; i++) {
//                string word = toVisit.front();
//                toVisit.pop();
//                if (word == endWord) return dist;
//                addNextWords(word, wordDict, toVisit);
//            }
//            dist++;
//        }
//     return 0;
//    }
//private:
//    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
//        wordDict.erase(word);
//        for (int p = 0; p < (int)word.length(); p++) {
//            char letter = word[p];
//            for (int k = 0; k < 26; k++) {
//                word[p] = 'a' + k;
//                if (wordDict.find(word) != wordDict.end()) {
//                    toVisit.push(word);
//                    wordDict.erase(word);
//                }
//            }
//            word[p] = letter;
//        }
//    }
